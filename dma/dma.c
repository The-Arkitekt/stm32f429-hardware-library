#include "dma.h"

void dma1Enable(){
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
}

void dma2Enable(){
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
}

void dma1Disable(){
    RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA1EN);
}

void dma2Disable(){
    RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA2EN);
}

Boolean dmaStreamConfigure(const Dma1StreamSelect streamSelect, const DmaStreamConfigStruct dmaConfig, 
                           const unsigned short maxDelayCycles){
    DMA_Stream_TypeDef* stream = (DMA_Stream_TypeDef*)streamSelect;
    WORD_TYPE tmp = 0U;

    // Must disable stream before initialization
    stream->CR &= ~(DMA_SxCR_EN);  //!< Clear the EN bit in the DMA_SxCR register

    // Wait until the bit is cleared or until max delay cycles are reached
    unsigned short int numDelayCycles = 0U;
    while((stream->CR & DMA_SxCR_EN) == DMA_SxCR_EN){
        if (++numDelayCycles >= maxDelayCycles){
            return FALSE;
        }
    }

    // Set the peripheral port register dest/src address
    stream->PAR = dmaConfig.peripheralAddress;

    // Set the memory dest/src address
    stream->M0AR = dmaConfig.memory0Address;

    // Set M1 address (used if double buffer mode is enabled)
    stream->M1AR = dmaConfig.memory1Address;
    
    // Set total number of data items per transfer
    stream->NDTR = dmaConfig.numDataItemsPerTransfer;

    tmp = stream->CR;

    // Clear and Set the DMA channel
    tmp &= ~(DMA_SxCR_CHSEL);
    tmp |= ((WORD_TYPE)(dmaConfig.channel) << DMA_SxCR_CHSEL_Pos);

    // Clear and set the Peripheral Flow Control enable
    tmp &= ~(DMA_SxCR_PFCTRL);
    tmp |= ((WORD_TYPE)(dmaConfig.peripheralFlowController) << DMA_SxCR_PFCTRL_Pos);
    
    // Clear and set the Stream Priority
    tmp &= ~(DMA_SxCR_PL);
    tmp |= ((WORD_TYPE)(dmaConfig.priorityLevel) << DMA_SxCR_PL_Pos);

    // Clear and set the data transfer direction
    tmp &= ~(DMA_SxCR_DIR);
    tmp |= ((WORD_TYPE)(dmaConfig.dataTransferDirection) << DMA_SxCR_DIR_Pos);

    // TODO: Finished configuring the CR register

    // TODO: Configure the FIFO Control register

    // TODO: Re-enable the stream

}

DMA_TypeDef* const getDmaFromStreamSelect(const DmaStreamSelect stream){
    if (stream == DMA1_STREAMSELECT_0 || stream == DMA1_STREAMSELECT_1 ||
        stream == DMA1_STREAMSELECT_2 || stream == DMA1_STREAMSELECT_3 ||
        stream == DMA1_STREAMSELECT_4 || stream == DMA1_STREAMSELECT_5 ||
        stream == DMA1_STREAMSELECT_6 || stream == DMA1_STREAMSELECT_7){

        return DMA1;
    }
    
    return DMA2;
}