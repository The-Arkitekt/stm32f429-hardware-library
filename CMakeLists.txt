# Set directories
set(SYSTEM_DIR                 ${CMAKE_CURRENT_SOURCE_DIR}/system)

set(CMSIS_INCLUDE_DIR          ${SYSTEM_DIR}/include/cmsis)

set(GPIO_SRC_DIR               ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/src)
set(GPIO_INCLUDE_DIR           ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/include)

####################################
#  Add STM32f429CommonLibrary 
#  libraries
####################################

# Gpio
add_library(Gpio ${GPIO_SRC_DIR}/Gpio.cpp)
target_include_directories(Gpio PUBLIC
  ${GPIO_INCLUDE_DIR}
  ${CMSIS_INCLUDE_DIR}
)



