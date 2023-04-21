#ifndef STM32F429_DMA_DEF_H
#define STM32F429_DMA_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32.h"

//	typedef struct
//	{
//	  __IO uint32_t CR;     /*!< DMA stream x configuration register      */
//	  __IO uint32_t NDTR;   /*!< DMA stream x number of data register     */
//	  __IO uint32_t PAR;    /*!< DMA stream x peripheral address register */
//	  __IO uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
//	  __IO uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
//	  __IO uint32_t FCR;    /*!< DMA stream x FIFO control register       */
//	} DMA_Stream_TypeDef;
typedef DMA_Stream_TypeDef * DMA_STREAM_TYPE;

typedef enum DmaStreamSelect{
	DMA_STREAMSELECT_0 = DMA1_Stream0_BASE,
	DMA_STREAMSELECT_1 = DMA1_Stream1_BASE,
	DMA_STREAMSELECT_2 = DMA1_Stream2_BASE,
	DMA_STREAMSELECT_3 = DMA1_Stream3_BASE,
	DMA_STREAMSELECT_4 = DMA1_Stream4_BASE,
	DMA_STREAMSELECT_5 = DMA1_Stream5_BASE,
	DMA_STREAMSELECT_6 = DMA1_Stream6_BASE,
	DMA_STREAMSELECT_7 = DMA1_Stream7_BASE
}DmaStreamSelect;

//typedef struct
//{
//  __IO uint32_t LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
//  __IO uint32_t HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
//  __IO uint32_t LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//  __IO uint32_t HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
//} DMA_TypeDef;
typedef DMA_TypeDef * DMA_TYPE;



/**
 * DMA Stream CR register
 */



#ifdef __cplusplus
}
#endif

#endif //STM32F429_DMA_DEF_H
