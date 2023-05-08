# Set directories

set(CONFIGURATION_FILE_PATH      ${CMAKE_SOURCE_DIR})

set(SYSTEM_INCLUDE_DIR           ${CMAKE_CURRENT_SOURCE_DIR}/system/include)
 
set(CMSIS_INCLUDE_DIR            ${SYSTEM_INCLUDE_DIR}/cmsis)

set(COMMON_DEF_DIR               ${CMAKE_CURRENT_SOURCE_DIR}/common/def)

set(GPIO_SRC_DIR                 ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/src)
set(GPIO_INCLUDE_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/include)
set(GPIO_DEF_DIR                 ${COMMON_DEF_DIR}/Gpio)

set(BIT_MANIPULATION_SRC_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/BitManipulation/src)
set(BIT_MANIPULATION_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/BitManipulation/include)

set(SYSTEM_CONFIG_SRC_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/SystemConfig/src)
set(SYSTEM_CONFIG_INCLUDE_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/SystemConfig/include)
set(SYSTEM_CONFIG_DEF_DIR        ${COMMON_DEF_DIR}/SystemConfig)

set(EXTI_SRC_DIR                 ${CMAKE_CURRENT_SOURCE_DIR}/Exti/src)
set(EXTI_INCLUDE_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/Exti/include)
set(EXTI_DEF_DIR                 ${COMMON_DEF_DIR}/Exti)


####################################
#  Add STM32f429CommonLibrary 
#  libraries
####################################

# BitManipulation
add_library(BitManipulation ${BIT_MANIPULATION_SRC_DIR}/BitManipulation.c)
target_include_directories(BitManipulation PUBLIC
  ${COMMON_DEF_DIR}
  ${BIT_MANIPULATION_INCLUDE_DIR}
)

# Gpio
add_library(Gpio ${GPIO_SRC_DIR}/Gpio.c)
target_include_directories(Gpio PUBLIC
  ${SYSTEM_INCLUDE_DIR}
  ${CONFIGURATION_FILE_PATH}
  ${GPIO_DEF_DIR}
  ${GPIO_INCLUDE_DIR}
  ${CMSIS_INCLUDE_DIR}
)
target_link_libraries(Gpio PUBLIC
  BitManipulation
)

#SystemConfig
add_library(SystemConfig ${SYSTEM_CONFIG_SRC_DIR}/SystemConfig.c)
target_include_directories(SystemConfig PUBLIC
  ${SYSTEM_INCLUDE_DIR}
  ${CONFIGURATION_FILE_PATH}
  ${GPIO_DEF_DIR}
  ${SYSTEM_CONFIG_DEF_DIR}
  ${SYSTEM_CONFIG_INCLUDE_DIR}
  ${CMSIS_INCLUDE_DIR}
)
target_link_libraries(SystemConfig PUBLIC
  BitManipulation
)

#Exti
add_library(Exti ${EXTI_SRC_DIR}/Exti.c)
target_include_directories(Exti PUBLIC
  ${SYSTEM_INCLUDE_DIR}
  ${CONFIGURATION_FILE_PATH}
  ${GPIO_DEF_DIR}
  ${EXTI_DEF_DIR}
  ${EXTI_INCLUDE_DIR}
  ${CMSIS_INCLUDE_DIR}
)
target_link_libraries(Exti PUBLIC
  BitManipulation
)


