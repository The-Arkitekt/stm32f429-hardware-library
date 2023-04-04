#include "Common.h"

uint32_t generate32BitMask(uint32_t seed, const uint8_t shiftAmt){
	return (uint32_t)(seed << shiftAmt);
}
