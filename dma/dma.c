#include "dma.h"

DMA_TypeDef* getDma(const DmaSelect dma)
{
    return (DMA_TypeDef*)(DMA1_BASE + ((BYTE_TYPE)dma * (DMA2_BASE - DMA1_BASE)));
}

DMA_Stream_TypeDef* getDmaStream(const DmaSelect dma, const DmaStreamSelect dmaStream)
{
    DMA_Stream_TypeDef* stream

    if (dma == DMA1_SELECT)
    {
        stream = (DMA_Stream_TypeDef*)(DMA1_Stream0_BASE + ((BYTE_TYPE)dmaStream * (DMA1_Stream7_BASE - DMA1_Stream0_BASE)));
    }
    else
    {
        stream = (DMA_Stream_Typedef*)(DMA2_Stream0_BASE + ((BYTE_TYPE)dmaStream * (DMA2_Stream7_BASE - DMA2_Stream0_BASE)));
    }

    return stream;
}

void setDmaStreamControl(DMA_Stream_TypeDef* const streamPtr, const DmaStreamControlFieldSelect field, BYTE_TYPE value)
{
    if (streamPtr != NULL)
    {
        BYTE_TYPE fieldMax = DMA_STREAM_CONTROL_FIELD_MAX[(BYTE_TYPE)field];

        if (value <= fieldMax)
        {
            BYTE_TYPE fieldPos = DMA_STREAM_CONTROL_FIELD_POS[(BYTE_TYPE)field];

            WORD_TYPE tmp = streamPtr->CR;
            tmp &= ~(fieldMax << fieldPos);
            tmp |= (value << fieldPos);

            streamPtr->CR = tmp;
        }
    }
}

Boolean readDmaStreamControl(const DMA_Stream_TypeDef* const streamPtr, 
                             const DmaStreamConfigFieldSelect field, BYTE_TYPE* const out)
{
    Boolean success = FALSE;
    if ((streamPtr != NULL) && (out != NULL))
    {
        WORD_TYPE tmp = streamPtr->CR >> DMA_STREAM_CONTROL_FIELD_POS[(BYTE_TYPE)field];
        (*out) = (BYTE_TYPE)(tmp & DMA_STREAM_CONTROL_FIELD_MAX[(BYTE_TYPE)field]);

        success = TRUE;  
    }  

    return success;
}

void clearDmaInterruptFlag(DMA_TypeDef* const dmaPtr, const DmaStreamSelect stream,
                           const DmaStreamInterruptTypeSelect interruptType)
{
    if (dmaPtr != NULL)
    {
        BYTE_TYPE streamIndex = (BYTE_TYPE)stream;
        WORD_TYPE* tmpPtr = dmaPtr.LISR;

        // May need to offset index to get position in register and set tmpPtr to High register
        if ((BYTE_TYPE)stream >= NUM_DMA_STREAMS_PER_INT_REG)
        {
            streamIndex -= NUM_DMA_STREAMS_PER_INT_REG;
            tmpPtr = dmaPtr.HISR;
        }

        BYTE_TYPE fieldPos = DMA_INTERRUPT_REG_STREAM_POS[(BYTE_TYPE)stream] + (BYTE_TYPE)interruptType;
        
        (*tmpPtr) |= (1U << fieldPos);
    }
}

Boolean readDmaInterruptFlag(const DMA_TypeDef* const dmaPtr, const DmaStreamSelect stream,
							 const DmaStreamInterruptTypeSelect interruptType, Boolean* const out)
{
    Boolean success = FALSE;
    if ((dmaPtr != NULL) && (out != NULL))
    {
        BYTE_TYPE streamIndex = (BYTE_TYPE)stream;
        WORD_TYPE tmp = dmaPtr->LIFCR;

        // May need to offset index to get position in register and set tmpPtr to High register
        if ((BYTE_TYPE)stream >= NUM_DMA_STREAMS_PER_INT_REG)
        {
            streamIndex -= NUM_DMA_STREAMS_PER_INT_REG;
            tmp = dmaPtr->HIFCR;
        }

        BYTE_TYPE fieldPos = DMA_INTERRUPT_REG_STREAM_POS[(BYTE_TYPE)stream] + (BYTE_TYPE)interruptType;
        (*out) = (((tmo >> fieldPos) & 1U) == 1U) ? TRUE : FALSE;

        success = TRUE;
    }

    return success;
}

void setDmaNumberItemsToTransfer(DMA_Stream_TypeDef* const streamPtr, const HALF_WORD numDataItems)
{
    if (streamPtr != NULL)
    {
        WORD_TYPE tmp = streamPtr->NDTR;
        
        tmp &= ~(HALF_WORD_MAX_VALUE);
        tmp |= (numDataItems);

        streamPtr->NDTR = tmp;
    }
}

Boolean readDmaNumberItemsToTransfer(const DMA_Stream_TypeDef* const streamPtr, HALF_WORD* const out)
{
    Boolean success = FALSE;
    if ((streamPtr != NULL) && (out != NULL))
    {
        (*out) = (HALF_WORD)(streamPtr->NDTR & HALF_WORD_MAX_VALUE);
        success = TRUE;
    }

    return success;
}   

void setDmaPeripheralAddress(DMA_Stream_TypeDef* const streamPtr, const WORD_TYPE address)
{   
    if (streamPtr != NULL)
    {
        streamPtr->PAR = address;
    }
}

Boolean readDmaPeripheralAddress(const DMA_Stream_TypeDef* const streamPtr, WORD_TYPE* const out)
{
    Boolean success = FALSE;
    if ((streamPtr != NULL) && (out != NULL))
    {
        (*out) = (WORD_TYPE)(streamPtr->PAR);
        success = TRUE;
    }

    return success;
}

void setDmaMemory0Address(DMA_Stream_TypeDef* const streamPtr, const WORD_TYPE address)
{
    if (streamPtr != NULL)
    {
        streamPtr->M0AR = address;
    }
}

Boolean readDmaMemory0Address(const DMA_Stream_TypeDef* const streamPtr, WORD_TYPE* const out)
{
    Boolean success = FALSE;
    if ((streamPtr != NULL) && (out != NULL))
    {
        (*out) = (WORD_TYPE)(streamPtr->M0AR);
        success = TRUE;
    }

    return success;
}

void setDmaMemory1Address(DMA_Stream_TypeDef* const streamPtr, const WORD_TYPE address)
{
    if (streamPtr != NULL)
    {
        streamPtr->M1AR = address;
    }
}

Boolean readDmaMemory1Address(const DMA_Stream_TypeDef* const streamPtr, WORD_TYPE* const out)
{
    Boolean success = FALSE;
    if ((streamPtr != NULL) && (out != NULL))
    {
        (*out) = (WORD_TYPE)(streamPtr->M1AR)
        success = TRUE;
    }

    return success;
}

void setDmaStreamFifoControl(DMA_Stream_TypeDef* const streamPtr, const DmaStreamFifoControlFieldSelect field, const BYTE_TYPE value)
{
    if (streamPtr != NULL)
    {
        BYTE_TYPE fieldMax = DMA_STREAM_FIFO_CONTROL_FIELD_MAX[(BYTE_TYPE)field];

        if (value <= fieldMax)
        {
            BYTE_TYPE fieldPos = DMA_STREAM_FIFO_CONTROL_FIELD_POS[(BYTE_TYPE)field];

            WORD_TYPE tmp = streamPtr->FCR;
            tmp &= ~(fieldMax << fieldPos);
            tmp |= (value << fieldPos);

            streamPtr->FCR = tmp;
        }
    }
}

Boolean readDmaStreamFifoControl(const DMA_Stream_TypeDef* const streamPtr, 
								 const setDmaStreamFifoControlFieldSelect field, BYTE_TYPE* const out)
{
    Boolean success = FALSE;
    if ((streamPtr != NULL) && (out != NULL))
    {
        WORD_TYPE tmp = streamPtr->FCR >> DMA_STREAM_FIFO_CONTROL_FIELD_POS[(BYTE_TYPE)field];
        (*out) = (BYTE_TYPE)(tmp & DMA_STREAM_FIFO_CONTROL_FIELD_MAX[(BYTE_TYPE)field]);

        success = TRUE;  
    }  

    return success;
}

void dma1Enable()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
}

void dma2Enable()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
}

void dma1Disable()
{
    RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA1EN);
}

void dma2Disable()
{
    RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA2EN);
}



