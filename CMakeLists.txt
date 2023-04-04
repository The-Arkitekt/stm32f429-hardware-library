# Set directories
set(SYSTEM_DIR                 ${CMAKE_CURRENT_SOURCE_DIR}/system)

set(CMSIS_INCLUDE_DIR          ${SYSTEM_DIR}/include/cmsis)

set(GPIO_SRC_DIR               ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/src)
set(GPIO_INCLUDE_DIR           ${CMAKE_CURRENT_SOURCE_DIR}/Gpio/include)

set(COMMON_SRC_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/Common/src)
set(COMMON_INCLUDE_DIR         ${CMAKE_CURRENT_SOURCE_DIR}/Common/include)

####################################
#  Add STM32f429CommonLibrary 
#  libraries
####################################

# Common
add_library(Common ${COMMON_SRC_DIR}/Common.c)
target_include_directories(Common PUBLIC
  ${COMMON_INCLUDE_DIR}
)

# Gpio
add_library(Gpio ${GPIO_SRC_DIR}/Gpio.c)
target_include_directories(Gpio PUBLIC
  ${GPIO_INCLUDE_DIR}
  ${CMSIS_INCLUDE_DIR}
)
target_link_libraries(Gpio PUBLIC
  Common
)



