# Set directories
set(DEVICE_LIB_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/deviceLibraries/${DEVICE})

set(CMSIS_DIR         ${DEVICE_LIB_DIR}/cmsis)

set(GPIO_DIR          ${CMAKE_CURRENT_SOURCE_DIR}/gpio)

set(SYSTEM_CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/systemConfig)

set(DMA_DIR           ${CMAKE_CURRENT_SOURCE_DIR}/dma)

set(EXTI_DIR          ${CMAKE_CURRENT_SOURCE_DIR}/exti)

set(TYPES_DIR         ${CMAKE_CURRENT_SOURCE_DIR}/types)

####################################
#  Add STM32f429CommonLibrary 
#  libraries
####################################

# Gpio
add_library(Gpio ${GPIO_DIR}/gpio.c)
target_include_directories(Gpio PUBLIC
  ${CMSIS_DIR}
  ${TYPES_DIR}
  ${GPIO_DIR}
)

#SystemConfig
add_library(SystemConfig ${SYSTEM_CONFIG_DIR}/systemConfig.c)
target_include_directories(SystemConfig PUBLIC
  ${CMSIS_DIR}
  ${TYPES_DIR}
  ${GPIO_DIR}
  ${SYSTEM_CONFIG_DIR}
)

#Exti
add_library(Exti ${EXTI_DIR}/exti.c)
target_include_directories(Exti PUBLIC
  ${CMSIS_DIR}
  ${TYPES_DIR}
  ${EXTI_DIR}
)

#Dma
add_library(Dma ${DMA_DIR}/dma.c)
target_include_directories(Dma PUBLIC
  ${CMSIS_DIR}
  ${TYPES_DIR}
  ${DMA_DIR}
)
