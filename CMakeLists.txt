# Set directories
set(DMA_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/dma)
set(EXTI_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/exti)
set(GPIO_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/gpio)
set(NVIC_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/nvic)
set(RCC_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/rcc)
set(SYSCFG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/syscfg)

####################################
#  Add STM32 Common libraries
####################################

#DMA
add_library(DMA ${DMA_DIR}/dma.c)
target_include_directories(DMA PUBLIC
  ${DMA_DIR}
)

#EXTI
add_library(EXTI ${EXTI_DIR}/exti.c)
target_include_directories(EXTI PUBLIC
  ${EXTI_DIR}
)

# GPIO
add_library(GPIO ${GPIO_DIR}/gpio.c)
target_include_directories(GPIO PUBLIC
  ${GPIO_DIR}
)

# NVIC
add_library(NVIC ${NVIC_DIR}/nvic.c)
target_include_directories(NVIC PUBLIC
  ${NVIC_DIR}
)

# RCC
add_library(RCC ${RCC_DIR}/rcc.c)
target_include_directories(RCC PUBLIC
  ${RCC_DIR}
)

# SYSCFG
add_library(SYSCFG ${SYSCFG_DIR}/syscfg.c)
target_include_directories(SYSCFG PUBLIC
  ${SYSCFG_DIR}
)
