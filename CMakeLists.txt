# Set directories

set(CONFIGURATION_FILE_PATH      ${CMAKE_SOURCE_DIR})

set(SYSTEM_INCLUDE_DIR                   ${CMAKE_CURRENT_SOURCE_DIR}/system/include)
 
set(CMSIS_INCLUDE_DIR            ${SYSTEM_INCLUDE_DIR}/cmsis)

set(COMMON_DEF_DIR               ${CMAKE_CURRENT_SOURCE_DIR}/common/def)

set(GPIO_SRC_DIR                 ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/src)
set(GPIO_INCLUDE_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/include)
set(GPIO_DEF_DIR                 ${COMMON_DEF_DIR}/Gpio)

set(BIT_MANIPULATION_SRC_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/BitManipulation/src)
set(BIT_MANIPULATION_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/BitManipulation/include)


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



