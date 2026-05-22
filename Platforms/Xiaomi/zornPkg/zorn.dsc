##
#
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = zorn
  PLATFORM_GUID                  = BABAD01C-A75F-4E97-A7E2-DF54AE7B7CEF
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/zornPkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = zornPkg/zorn.fdf
  USE_CUSTOM_DISPLAY_DRIVER      = 0
  HAS_BUILD_IN_KEYBOARD          = 0

  # If your SoC has multimple variants define the Number here
  # If not don't add this Define
  SOC_TYPE                       = 0

[LibraryClasses]
  MemoryMapLib|zornPkg/Library/MemoryMapLib/MemoryMapLib.inf
  ConfigurationMapLib|zornPkg/Library/ConfigurationMapLib/ConfigurationMapLib.inf

[PcdsFixedAtBuild]
  # DDR Start Address
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x816E0000
  gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x80080246

  # UEFI Stack Addresses
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0xA760D000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemManufacturer|"RedMi"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemModel|"K80"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"zorn"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"24117RK2CC"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosBoardModel|"24117RK2CC"

  # Simple FrameBuffer
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferWidth|1440
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferHeight|3200
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferColorDepth|32

  # Platform Pei
  gQcomPkgTokenSpaceGuid.PcdPlatformType|"LA"
  gQcomPkgTokenSpaceGuid.PcdScheduleInterfaceAddr|0xA703FD38
  gQcomPkgTokenSpaceGuid.PcdDtbExtensionAddr|0xA703F0E8

  # Dynamic RAM Start Address
  gSiliciumPkgTokenSpaceGuid.PcdRamPartitionBase|0xFEF00000

  # SD Card Slot
  gQcomPkgTokenSpaceGuid.PcdInitCardSlot|FALSE            # If your Phone has no SD Card Slot, Set it to FALSE.

!include LanaiPkg/LanaiPkg.dsc.inc