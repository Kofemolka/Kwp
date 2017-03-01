#This file is generated by VisualGDB.
#It contains GCC settings automatically derived from the board support package (BSP).
#DO NOT EDIT MANUALLY. THE FILE WILL BE OVERWRITTEN. 
#Use VisualGDB Project Properties dialog or modify Makefile or per-configuration .mak files instead.

#VisualGDB provides BSP_ROOT and TOOLCHAIN_ROOT via environment when running Make. The line below will only be active if GNU Make is started manually.
BSP_ROOT ?= $(LOCALAPPDATA)/VisualGDB/EmbeddedBSPs/arm-eabi/com.sysprogs.arm.nordic.nrf5x
EFP_BASE ?= $(LOCALAPPDATA)/VisualGDB/EmbeddedEFPs
TOOLCHAIN_ROOT ?= E:/Zved/nRF/Toolchains

#Embedded toolchain
CC := $(TOOLCHAIN_ROOT)/bin/arm-eabi-gcc.exe
CXX := $(TOOLCHAIN_ROOT)/bin/arm-eabi-g++.exe
LD := $(CXX)
AR := $(TOOLCHAIN_ROOT)/bin/arm-eabi-ar.exe
OBJCOPY := $(TOOLCHAIN_ROOT)/bin/arm-eabi-objcopy.exe

#Additional flags
PREPROCESSOR_MACROS += NRF52 NRF52832 S132 NRF_DFU_SETTINGS_VERSION=1 NRF_SD_BLE_API_VERSION=3 ARM_MATH_CM4 BOARD_PCA10040 BSP_SIMPLE  BLE_STACK_SUPPORT_REQD SOFTDEVICE_PRESENT SWI_DISABLE0
INCLUDE_DIRS += . $(BSP_ROOT)/nRF5x/components/softdevice/S132/headers $(BSP_ROOT)/nRF5x/components/toolchain $(BSP_ROOT)/nRF5x/components/toolchain/cmsis/include $(BSP_ROOT)/nRF5x/components/device $(BSP_ROOT)/nRF5x/components/softdevice/common/softdevice_handler $(BSP_ROOT)/nRF5x/components/drivers_nrf/adc $(BSP_ROOT)/nRF5x/components/drivers_nrf/ble_flash $(BSP_ROOT)/nRF5x/components/drivers_nrf/clock $(BSP_ROOT)/nRF5x/components/drivers_nrf/common $(BSP_ROOT)/nRF5x/components/drivers_nrf/comp $(BSP_ROOT)/nRF5x/components/drivers_nrf/delay $(BSP_ROOT)/nRF5x/components/drivers_nrf/gpiote $(BSP_ROOT)/nRF5x/components/drivers_nrf/hal $(BSP_ROOT)/nRF5x/components/drivers_nrf/i2s $(BSP_ROOT)/nRF5x/components/drivers_nrf/lpcomp $(BSP_ROOT)/nRF5x/components/drivers_nrf/nrf_soc_nosd $(BSP_ROOT)/nRF5x/components/drivers_nrf/pdm $(BSP_ROOT)/nRF5x/components/drivers_nrf/ppi $(BSP_ROOT)/nRF5x/components/drivers_nrf/pwm $(BSP_ROOT)/nRF5x/components/drivers_nrf/qdec $(BSP_ROOT)/nRF5x/components/drivers_nrf/radio_config $(BSP_ROOT)/nRF5x/components/drivers_nrf/rng $(BSP_ROOT)/nRF5x/components/drivers_nrf/rtc $(BSP_ROOT)/nRF5x/components/drivers_nrf/saadc $(BSP_ROOT)/nRF5x/components/drivers_nrf/sdio $(BSP_ROOT)/nRF5x/components/drivers_nrf/sdio/config $(BSP_ROOT)/nRF5x/components/drivers_nrf/spi_master $(BSP_ROOT)/nRF5x/components/drivers_nrf/spi_slave $(BSP_ROOT)/nRF5x/components/drivers_nrf/swi $(BSP_ROOT)/nRF5x/components/drivers_nrf/timer $(BSP_ROOT)/nRF5x/components/drivers_nrf/twis_slave $(BSP_ROOT)/nRF5x/components/drivers_nrf/twi_master $(BSP_ROOT)/nRF5x/components/drivers_nrf/twi_master/deprecated $(BSP_ROOT)/nRF5x/components/drivers_nrf/twi_master/deprecated/config $(BSP_ROOT)/nRF5x/components/drivers_nrf/uart $(BSP_ROOT)/nRF5x/components/drivers_nrf/wdt $(BSP_ROOT)/nRF5x/components/libraries/util $(BSP_ROOT)/nRF5x/examples/bsp $(BSP_ROOT)/nRF5x/components/libraries/bootloader $(BSP_ROOT)/nRF5x/components/libraries/bootloader/ble_dfu $(BSP_ROOT)/nRF5x/components/libraries/bootloader/dfu $(BSP_ROOT)/nRF5x/components/libraries/button $(BSP_ROOT)/nRF5x/components/libraries/crc16 $(BSP_ROOT)/nRF5x/components/libraries/crc32 $(BSP_ROOT)/nRF5x/components/libraries/crypto $(BSP_ROOT)/nRF5x/components/libraries/csense $(BSP_ROOT)/nRF5x/components/libraries/csense_drv $(BSP_ROOT)/nRF5x/components/libraries/ecc $(BSP_ROOT)/nRF5x/components/libraries/experimental_section_vars $(BSP_ROOT)/nRF5x/components/libraries/fds $(BSP_ROOT)/nRF5x/components/libraries/fifo $(BSP_ROOT)/nRF5x/components/libraries/fstorage $(BSP_ROOT)/nRF5x/components/libraries/gpiote $(BSP_ROOT)/nRF5x/components/libraries/hardfault $(BSP_ROOT)/nRF5x/components/libraries/hci $(BSP_ROOT)/nRF5x/components/libraries/ic_info $(BSP_ROOT)/nRF5x/components/libraries/led_softblink $(BSP_ROOT)/nRF5x/components/libraries/log $(BSP_ROOT)/nRF5x/components/libraries/log/src $(BSP_ROOT)/nRF5x/components/libraries/low_power_pwm $(BSP_ROOT)/nRF5x/components/libraries/mailbox $(BSP_ROOT)/nRF5x/components/libraries/pwm $(BSP_ROOT)/nRF5x/components/libraries/scheduler $(BSP_ROOT)/nRF5x/components/libraries/sensorsim $(BSP_ROOT)/nRF5x/components/libraries/sha256 $(BSP_ROOT)/nRF5x/components/libraries/simple_timer $(BSP_ROOT)/nRF5x/components/libraries/slip $(BSP_ROOT)/nRF5x/components/libraries/svc $(BSP_ROOT)/nRF5x/components/libraries/timer $(BSP_ROOT)/nRF5x/components/libraries/twi $(BSP_ROOT)/nRF5x/components/libraries/uart $(BSP_ROOT)/nRF5x/components/libraries/util $(BSP_ROOT)/nRF5x/components/softdevice/common/softdevice_handler $(BSP_ROOT)/nRF5x/components/ble/common $(BSP_ROOT)/nRF5x/ble_services/ble_nus
LIBRARY_DIRS += $(BSP_ROOT)/nRF5x/SoftdeviceLibraries
LIBRARY_NAMES += 
ADDITIONAL_LINKER_INPUTS += 
MACOS_FRAMEWORKS += 
LINUX_PACKAGES += 

CFLAGS += -std=gnu99 
CXXFLAGS += 
ASFLAGS += -mfpu=fpv4-sp-d16
LDFLAGS += --specs=nano.specs --specs=nosys.specs
COMMONFLAGS += -mabi=aapcs  -mcpu=cortex-m4 -mthumb -mfloat-abi=hard
LINKER_SCRIPT := $(BSP_ROOT)/nRF5x/LinkerScripts/nRF52832_XXAA_S132_32k.lds

