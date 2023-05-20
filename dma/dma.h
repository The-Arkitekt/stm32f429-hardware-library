#ifndef DMA_H
#define DMA_H

#ifdef __cplusplus
	extern "C" {
#endif
 
#include "dmaTypes.h"

//@{
/**
 * Enable the DMA1 peripheral in the RCC register
*/
void dma1Enable();
void dma2Enable();
//@}

//@{
/** 
 * Disable the DMA2 peripheral in the RCC register
*/
void dma1Disable();
void dma2Disable();
//@}

/**
 * Configure a DMA Stream
 * @param streamSelect The DMA stream to configure
 * @param dmaConfig The struct containing the desired configuration of the stream
 * @param maxDelayCycles The max number of delay loop cycles to wait for EN to clear before returning false
 * @return True if successful, false otherwise
*/
Boolean dmaStreamConfigure(const DmaStreamSelect streamSelect, const DmaStreamConfigStruct dmaConfig, 
					       const unsigned int maxDelayCycles);

/**
 * Check if Transfer is complete
 * @param stream The DMA Stream to checl
 * @return The current status of the stream FIFO buffer
*/
DmaStreamFcrFifoStatus getDmaStreamTransferStatus(const DmaStreamSelect stream);

/**
 * Get either DMA1 or DMA2 based on the stream selection
 * @param stream THe stream selection used to decide the DMA
 * @return The pointer to the DMA struct in memory
*/
DMA_TypeDef* const getDmaFromStreamSelect(const DmaStreamSelect stream);







#ifdef __cplusplus
}
#endif

#endif //DMA_H
