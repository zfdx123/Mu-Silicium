##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

[Defines]
  # GIC
  USE_CUSTOM_GIC                             = 0

  # Timer
  USE_CUSTOM_TIMER                           = 0
  USE_PHYSICAL_TIMER                         = 0

  # KEP
  ENABLE_KEP                                 = 0
  HAS_ACTLR_EL1_UNIMPLEMENTED_ERRATA         = 0
  HAS_AMCNTENSET0_EL0_UNIMPLEMENTED_ERRATA   = 0
  HAS_GIC_V3_WITHOUT_IRM_FLAG_SUPPORT_ERRATA = 0
  HAS_PSCI_MEMPROTECT_FAILING_ERRATA         = 0

[BuildOptions]
  *_*_AARCH64_CC_FLAGS = -march=armv9.2-a+crypto+rcpc

[PcdsFixedAtBuild]
  # FV Decompress Address
  gQcomPkgTokenSpaceGuid.PcdFvDecompressAddr|0xA704D0B8

  # Memory
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiACPIReclaimMemory|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiACPIMemoryNVS|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiReservedMemoryType|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesData|80
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesCode|40
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiBootServicesCode|400
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiBootServicesData|800
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiLoaderCode|10
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiLoaderData|0

  # CPU
  gArmPlatformTokenSpaceGuid.PcdCoreCount|8
  gArmPlatformTokenSpaceGuid.PcdClusterCount|3

  # GIC
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x17100000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0x17180000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0x17180000

  # Timer
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|29
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|30
  gArmTokenSpaceGuid.PcdArmArchTimerVirtIntrNum|27
  gArmTokenSpaceGuid.PcdArmArchTimerHypIntrNum|26

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Snapdragon (TM) 8 Gen 3"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorPartNumber|"SM8650"

  # SmBios CPU Extras
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMaxCpuFreq|3300
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel1InstCacheSize|0x20
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel1DataCacheSize|0x20
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel2CacheSize|0x400
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel3CacheSize|0x2000         # Unoffical Value

  # SmBios Memory Extras
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMemorySpeed|4800
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMemoryType|35

[LibraryClasses]
  #
  # SEC Libraries
  #
  PlatformSecLib|LanaiPkg/Library/PlatformSecLib/PlatformSecLib.inf

  #
  # ACPI Libraries
  #
  AcpiTableUpdateLib|LanaiPkg/Library/AcpiTableUpdateLib/AcpiTableUpdateLib.inf

  #
  # Custom Libraries
  #
  RFSProtectionLib|LanaiPkg/Library/RFSProtectionLib/RFSProtectionLib.inf

!include QcomPkg/QcomPkg.dsc.inc
