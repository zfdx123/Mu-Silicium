/**
  Copyright (c) 2011-2012, ARM Limited. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/IoLib.h>
#include <Library/PlatformSecLib.h>
#include <Library/ConfigurationMapHelperLib.h>
#include <Library/ArmSmmuDetachLib.h>

#include "PlatformRegisters.h"

STATIC
ARM_CORE_INFO
mArmPlatformMpCoreInfoTable[] = {
  // Mpidr, MailboxSetAddress, MailboxGetAddress, MailboxClearAddress, MailboxClearValue
  //
  // Cluster 0 - Cortex-X4
  //
  { 0x000, 0, 0, 0, 0xFFFFFFFF },

  //
  // Cluster 1 - Cortex-A720
  //
  { 0x10000, 0, 0, 0, 0xFFFFFFFF },
  { 0x10100, 0, 0, 0, 0xFFFFFFFF },
  { 0x10200, 0, 0, 0, 0xFFFFFFFF },
  { 0x10300, 0, 0, 0, 0xFFFFFFFF },
  { 0x10400, 0, 0, 0, 0xFFFFFFFF },

  //
  // Cluster 2 - Cortex-A520
  //
  { 0x20000, 0, 0, 0, 0xFFFFFFFF },
  { 0x20100, 0, 0, 0, 0xFFFFFFFF }
};

VOID
GetPlatformCoreTable (
  OUT ARM_CORE_INFO **ArmCoreTable,
  OUT UINTN          *CoreCount)
{
  // Pass Data
  *ArmCoreTable = mArmPlatformMpCoreInfoTable;
  *CoreCount    = ARRAY_SIZE (mArmPlatformMpCoreInfoTable);
}

VOID
WakeUpCores ()
{
  EFI_STATUS Status;
  UINT32     EarlyInitCoreCnt;

  // Get Early Cores Count
  Status = LocateConfigurationEntry32 ("EarlyInitCoreCnt", &EarlyInitCoreCnt);
  if (EFI_ERROR (Status)) {
    return;
  }

  // Wake Up all Cores
  for (UINTN i = 0; i < EarlyInitCoreCnt; i++) {
    UINT32 Value;

    // Modify current GIC Waker
    Value  = MmioRead32 (GICR_WAKER_CPU (i));
    Value &= ~GIC_WAKER_PROCESSORSLEEP;

    // Write new GIC Waker
    MmioWrite32 (GICR_WAKER_CPU (i), Value);
  }
}

VOID
PlatformInitialize ()
{
  WakeUpCores();
  
  // Set MDP SIDs
  CONST UINT16 MdpStreams[] = { 0x1C00, 0x1C02, 0x1C01 };

  // Detach IOMMU Domains
  ArmSmmuDetach (MdpStreams, ARRAY_SIZE (MdpStreams));
}
