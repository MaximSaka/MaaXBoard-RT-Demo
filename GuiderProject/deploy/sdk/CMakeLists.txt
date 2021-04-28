INCLUDE(CMakeForceCompiler)

# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

 
# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})


SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DDEBUG")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -g")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Wall")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mthumb")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-common")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mapcs")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -std=gnu99")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DNDEBUG")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Wall")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mthumb")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-common")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mapcs")

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -std=gnu99")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DXIP_EXTERNAL_FLASH=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DXIP_BOOT_HEADER_ENABLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DXIP_BOOT_HEADER_DCD_ENABLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DSKIP_SYSCLK_INIT")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DDATA_SECTION_IS_CACHEABLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DDEBUG")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DCPU_MIMXRT1062DVL6A")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DLV_CONF_INCLUDE_SIMPLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DLV_EX_CONF_INCLUDE_SIMPLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DSERIAL_PORT_TYPE_UART=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -g")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -O0")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Wall")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mthumb")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -MMD")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -MP")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-common")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mapcs")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -std=gnu99")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DXIP_EXTERNAL_FLASH=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DXIP_BOOT_HEADER_ENABLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DXIP_BOOT_HEADER_DCD_ENABLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DSKIP_SYSCLK_INIT")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DDATA_SECTION_IS_CACHEABLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DNDEBUG")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DCPU_MIMXRT1062DVL6A")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DLV_CONF_INCLUDE_SIMPLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DLV_EX_CONF_INCLUDE_SIMPLE=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DSERIAL_PORT_TYPE_UART=1")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Os")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Wall")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mthumb")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -MMD")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -MP")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-common")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mapcs")

SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -std=gnu99")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DDEBUG")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -DSERIAL_PORT_TYPE_UART=1")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -g")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -O0")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mthumb")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -MMD")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -MP")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-common")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mapcs")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-rtti")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DNDEBUG")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -DSERIAL_PORT_TYPE_UART=1")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Os")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Wall")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mthumb")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -MMD")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -MP")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-common")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mapcs")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-rtti")

SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-exceptions")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -g")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -static")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -z")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -Map=output.map")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -static")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -z")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -Map=output.map")

#include_directories(${ProjDirPath}/..)
include_directories(${ProjDirPath}/littlevgl/lvgl)
include_directories(${ProjDirPath}/drivers)
include_directories(${ProjDirPath}/xip)
include_directories(${ProjDirPath}/freertos/freertos_kernel/include)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_core)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_hal)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_gpu)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_themes)
include_directories(${ProjDirPath}/littlevgl/lv_examples)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_draw)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_widgets)
include_directories(${ProjDirPath}/freertos/freertos_kernel/portable/GCC/ARM_CM4F)
include_directories(${ProjDirPath}/device)
include_directories(${ProjDirPath}/component/lists)
include_directories(${ProjDirPath}/component/uart)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_font)
include_directories(${ProjDirPath}/littlevgl/lvgl/src)
include_directories(${ProjDirPath}/CMSIS)
include_directories(${ProjDirPath}/littlevgl/lvgl/porting)
include_directories(${ProjDirPath}/touchpanel)
include_directories(${ProjDirPath}/littlevgl)
include_directories(${ProjDirPath}/board)
include_directories(${ProjDirPath}/littlevgl/lv_examples/src/lv_demo_widgets)
include_directories(${ProjDirPath}/component/serial_manager)
include_directories(${ProjDirPath}/littlevgl/lvgl/src/lv_misc)
include_directories(${ProjDirPath}/startup)
include_directories(${ProjDirPath}/utilities)
include_directories(${ProjDirPath}/source)

include_directories(${ProjDirPath}/custom)
include_directories(${ProjDirPath}/generated)
include_directories(${ProjDirPath}/generated/images)
include_directories(${ProjDirPath}/generated/guider_fonts)
include_directories(${ProjDirPath}/generated/guider_customer_fonts)

#include_directories(${ProjDirPath}/../../..)

#include_directories(${ProjDirPath}/..)

#include_directories(${ProjDirPath}/../../..)

#include_directories(${ProjDirPath}/../../../../../rtos/freertos/freertos_kernel/portable/GCC/ARM_CM4F)

#include_directories(${ProjDirPath}/..)

#include_directories(${ProjDirPath}/../..)

#include_directories(${ProjDirPath}/../../..)

#include_directories(${ProjDirPath}/../../../../../middleware/littlevgl)

#include_directories(${ProjDirPath}/../../../../../CMSIS/Include)

#include_directories(${ProjDirPath}/../../../../../devices)

#include_directories(${ProjDirPath}/../../../../../rtos/freertos/freertos_kernel/include)

#include_directories(${ProjDirPath}/../../../../../devices/MIMXRT1062/drivers)

#include_directories(${ProjDirPath}/../../../../../components/ft5406_rt)

#include_directories(${ProjDirPath}/../../../../../middleware/littlevgl/lvgl)

#include_directories(${ProjDirPath}/../../../../../devices/MIMXRT1062)

#include_directories(${ProjDirPath}/../../../../../devices/MIMXRT1062/utilities/str)

#include_directories(${ProjDirPath}/../../../../../devices/MIMXRT1062/utilities/debug_console)

#include_directories(${ProjDirPath}/../../../../../components/uart)

#include_directories(${ProjDirPath}/../../../../../components/serial_manager)

#include_directories(${ProjDirPath}/../../../../../components/lists)

#include_directories(${ProjDirPath}/../../../../../devices/MIMXRT1062/xip)

#include_directories(${ProjDirPath}/../../../xip)

#include_directories(${ProjDirPath}/../../../../../devices/MIMXRT1062/utilities)

file(GLOB SOURCES
    ${ProjDirPath}/custom/*.c
    ${ProjDirPath}/custom/*.h
    ${ProjDirPath}/generated/*.c
    ${ProjDirPath}/generated/*.h
    ${ProjDirPath}/generated/images/*.c
    ${ProjDirPath}/generated/images/*.h
    ${ProjDirPath}/generated/guider_fonts/*.c
    ${ProjDirPath}/generated/guider_fonts/*.h
    ${ProjDirPath}/generated/guider_customer_fonts/*.c
    ${ProjDirPath}/generated/guider_customer_fonts/*.h
    ${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_anim_img.c
    ${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_anim_img.h
)
 

add_executable(littlevgl_demo_widgets.elf 
"${ProjDirPath}/board/board.c"
"${ProjDirPath}/board/board.h"
"${ProjDirPath}/board/clock_config.c"
"${ProjDirPath}/board/clock_config.h"
"${ProjDirPath}/board/dcd.c"
"${ProjDirPath}/board/dcd.h"
"${ProjDirPath}/board/littlevgl_support.c"
"${ProjDirPath}/board/littlevgl_support.h"
"${ProjDirPath}/board/pin_mux.c"
"${ProjDirPath}/board/pin_mux.h"
"${ProjDirPath}/CMSIS/arm_common_tables.h"
"${ProjDirPath}/CMSIS/arm_const_structs.h"
"${ProjDirPath}/CMSIS/arm_math.h"
"${ProjDirPath}/CMSIS/cmsis_armcc.h"
"${ProjDirPath}/CMSIS/cmsis_armclang.h"
"${ProjDirPath}/CMSIS/cmsis_armclang_ltm.h"
"${ProjDirPath}/CMSIS/cmsis_compiler.h"
"${ProjDirPath}/CMSIS/cmsis_gcc.h"
"${ProjDirPath}/CMSIS/cmsis_iccarm.h"
"${ProjDirPath}/CMSIS/cmsis_version.h"
"${ProjDirPath}/CMSIS/core_cm7.h"
"${ProjDirPath}/CMSIS/mpu_armv7.h"
"${ProjDirPath}/component/lists/generic_list.c"
"${ProjDirPath}/component/lists/generic_list.h"
"${ProjDirPath}/component/serial_manager/serial_manager.c"
"${ProjDirPath}/component/serial_manager/serial_manager.h"
"${ProjDirPath}/component/serial_manager/serial_port_internal.h"
"${ProjDirPath}/component/serial_manager/serial_port_uart.c"
"${ProjDirPath}/component/serial_manager/serial_port_uart.h"
"${ProjDirPath}/component/uart/lpuart_adapter.c"
"${ProjDirPath}/component/uart/uart.h"
"${ProjDirPath}/device/fsl_device_registers.h"
"${ProjDirPath}/device/MIMXRT1062.h"
"${ProjDirPath}/device/MIMXRT1062_features.h"
"${ProjDirPath}/device/system_MIMXRT1062.c"
"${ProjDirPath}/device/system_MIMXRT1062.h"
"${ProjDirPath}/drivers/fsl_cache.c"
"${ProjDirPath}/drivers/fsl_cache.h"
"${ProjDirPath}/drivers/fsl_clock.c"
"${ProjDirPath}/drivers/fsl_clock.h"
"${ProjDirPath}/drivers/fsl_common.c"
"${ProjDirPath}/drivers/fsl_common.h"
"${ProjDirPath}/drivers/fsl_elcdif.c"
"${ProjDirPath}/drivers/fsl_elcdif.h"
"${ProjDirPath}/drivers/fsl_gpio.c"
"${ProjDirPath}/drivers/fsl_gpio.h"
"${ProjDirPath}/drivers/fsl_iomuxc.h"
"${ProjDirPath}/drivers/fsl_lpi2c.c"
"${ProjDirPath}/drivers/fsl_lpi2c.h"
"${ProjDirPath}/drivers/fsl_lpuart.c"
"${ProjDirPath}/drivers/fsl_lpuart.h"
"${ProjDirPath}/drivers/fsl_pxp.c"
"${ProjDirPath}/drivers/fsl_pxp.h"
"${ProjDirPath}/freertos/freertos_kernel/croutine.c"
"${ProjDirPath}/freertos/freertos_kernel/event_groups.c"
"${ProjDirPath}/freertos/freertos_kernel/include/atomic.h"
"${ProjDirPath}/freertos/freertos_kernel/include/croutine.h"
"${ProjDirPath}/freertos/freertos_kernel/include/deprecated_definitions.h"
"${ProjDirPath}/freertos/freertos_kernel/include/event_groups.h"
"${ProjDirPath}/freertos/freertos_kernel/include/FreeRTOS.h"
"${ProjDirPath}/freertos/freertos_kernel/include/freertos_tasks_c_additions.h"
"${ProjDirPath}/freertos/freertos_kernel/include/list.h"
"${ProjDirPath}/freertos/freertos_kernel/include/message_buffer.h"
"${ProjDirPath}/freertos/freertos_kernel/include/mpu_prototypes.h"
"${ProjDirPath}/freertos/freertos_kernel/include/mpu_wrappers.h"
"${ProjDirPath}/freertos/freertos_kernel/include/portable.h"
"${ProjDirPath}/freertos/freertos_kernel/include/projdefs.h"
"${ProjDirPath}/freertos/freertos_kernel/include/queue.h"
"${ProjDirPath}/freertos/freertos_kernel/include/semphr.h"
"${ProjDirPath}/freertos/freertos_kernel/include/stack_macros.h"
"${ProjDirPath}/freertos/freertos_kernel/include/StackMacros.h"
"${ProjDirPath}/freertos/freertos_kernel/include/stream_buffer.h"
"${ProjDirPath}/freertos/freertos_kernel/include/task.h"
"${ProjDirPath}/freertos/freertos_kernel/include/timers.h"
"${ProjDirPath}/freertos/freertos_kernel/list.c"
"${ProjDirPath}/freertos/freertos_kernel/portable/GCC/ARM_CM4F/port.c"
"${ProjDirPath}/freertos/freertos_kernel/portable/GCC/ARM_CM4F/portmacro.h"
"${ProjDirPath}/freertos/freertos_kernel/portable/MemMang/heap_4.c"
"${ProjDirPath}/freertos/freertos_kernel/queue.c"
"${ProjDirPath}/freertos/freertos_kernel/stream_buffer.c"
"${ProjDirPath}/freertos/freertos_kernel/tasks.c"
"${ProjDirPath}/freertos/freertos_kernel/timers.c"
"${ProjDirPath}/littlevgl/lv_examples/lv_examples.h"
"${ProjDirPath}/littlevgl/lv_examples/src/lv_demo_widgets/lv_demo_widgets.c"
"${ProjDirPath}/littlevgl/lv_examples/src/lv_demo_widgets/lv_demo_widgets.h"
"${ProjDirPath}/littlevgl/lvgl/lvgl.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_api_map.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_conf_internal.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_debug.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_debug.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_disp.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_disp.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_group.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_group.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_indev.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_indev.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_obj.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_obj.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_obj_style_dec.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_refr.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_refr.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_style.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_core/lv_style.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_arc.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_arc.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_blend.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_blend.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_img.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_img.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_label.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_label.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_line.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_line.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_mask.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_mask.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_rect.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_rect.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_triangle.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_draw_triangle.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_img_buf.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_img_buf.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_img_cache.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_img_cache.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_img_decoder.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_draw/lv_img_decoder.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_dejavu_16_persian_hebrew.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_fmt_txt.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_fmt_txt.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_12.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_12_subpx.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_14.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_16.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_18.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_20.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_22.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_24.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_26.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_28.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_28_compressed.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_30.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_32.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_34.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_36.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_38.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_40.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_42.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_44.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_46.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_montserrat_48.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_simsun_16_cjk.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_font_unscii_8.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_font/lv_symbol_def.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_hal/lv_hal.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_hal/lv_hal_disp.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_hal/lv_hal_disp.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_hal/lv_hal_indev.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_hal/lv_hal_indev.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_hal/lv_hal_tick.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_hal/lv_hal_tick.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_anim.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_anim.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_area.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_area.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_async.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_async.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_bidi.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_bidi.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_color.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_color.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_fs.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_fs.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_gc.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_gc.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_ll.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_ll.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_log.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_log.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_math.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_math.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_mem.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_mem.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_printf.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_printf.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_task.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_task.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_templ.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_templ.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_txt.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_txt.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_txt_ap.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_txt_ap.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_types.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_utils.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_misc/lv_utils.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_empty.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_empty.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_material.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_material.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_mono.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_mono.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_template.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_themes/lv_theme_template.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_arc.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_arc.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_bar.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_bar.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_btn.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_btn.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_btnmatrix.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_btnmatrix.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_calendar.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_calendar.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_canvas.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_canvas.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_chart.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_chart.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_checkbox.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_checkbox.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_cont.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_cont.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_cpicker.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_cpicker.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_dropdown.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_dropdown.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_gauge.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_gauge.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_img.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_img.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_imgbtn.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_imgbtn.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_keyboard.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_keyboard.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_label.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_label.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_led.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_led.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_line.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_line.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_linemeter.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_linemeter.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_list.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_list.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_msgbox.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_msgbox.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_objmask.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_objmask.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_objx_templ.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_objx_templ.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_page.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_page.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_roller.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_roller.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_slider.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_slider.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_spinbox.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_spinbox.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_spinner.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_spinner.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_switch.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_switch.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_table.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_table.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_tabview.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_tabview.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_textarea.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_textarea.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_tileview.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_tileview.h"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_win.c"
"${ProjDirPath}/littlevgl/lvgl/src/lv_widgets/lv_win.h"
"${ProjDirPath}/MIMXRT1062/gcc/MIMXRT1062xxxxx_ram.ld"
"${ProjDirPath}/source/FreeRTOSConfig.h"
"${ProjDirPath}/source/littlevgl_demo_widgets.c"
"${ProjDirPath}/source/lv_conf.h"
"${ProjDirPath}/source/lv_ex_conf.h"
"${ProjDirPath}/startup/startup_MIMXRT1062.S"
"${ProjDirPath}/touchpanel/fsl_ft5406_rt.c"
"${ProjDirPath}/touchpanel/fsl_ft5406_rt.h"
"${ProjDirPath}/utilities/fsl_assert.c"
"${ProjDirPath}/utilities/fsl_debug_console.c"
"${ProjDirPath}/utilities/fsl_debug_console.h"
"${ProjDirPath}/utilities/fsl_debug_console_conf.h"
"${ProjDirPath}/utilities/fsl_sbrk.c"
"${ProjDirPath}/utilities/fsl_str.c"
"${ProjDirPath}/utilities/fsl_str.h"
"${ProjDirPath}/xip/evkmimxrt1060_flexspi_nor_config.c"
"${ProjDirPath}/xip/evkmimxrt1060_flexspi_nor_config.h"
"${ProjDirPath}/xip/fsl_flexspi_nor_boot.c"
"${ProjDirPath}/xip/fsl_flexspi_nor_boot.h"
${SOURCES}
)


set(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} -T${ProjDirPath}/MIMXRT1062xxxxx_flexspi_nor_sdram.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} -T${ProjDirPath}/MIMXRT1062xxxxx_flexspi_nor_sdram.ld -static")

TARGET_LINK_LIBRARIES(littlevgl_demo_widgets.elf -Wl,--start-group)
target_link_libraries(littlevgl_demo_widgets.elf optimized m)

target_link_libraries(littlevgl_demo_widgets.elf optimized c)

target_link_libraries(littlevgl_demo_widgets.elf optimized gcc)

target_link_libraries(littlevgl_demo_widgets.elf optimized nosys)

target_link_libraries(littlevgl_demo_widgets.elf optimized m)

target_link_libraries(littlevgl_demo_widgets.elf optimized c)

target_link_libraries(littlevgl_demo_widgets.elf optimized gcc)

target_link_libraries(littlevgl_demo_widgets.elf optimized nosys)

TARGET_LINK_LIBRARIES(littlevgl_demo_widgets.elf -Wl,--end-group)


