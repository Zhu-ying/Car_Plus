#ifndef __GPIO_H
#define __GPIO_H

#include "stm32f10x.h"

// GPIO mode
typedef enum {
    GPIO_MODE_IN_FLOATING,  // floating
    GPIO_MODE_IPU,         // ????????
    GPIO_MODE_IPD,         // ????????
    GPIO_MODE_OUT_PP,      // ????
    GPIO_MODE_OUT_OD,      // ????
    GPIO_MODE_AF_PP,       // ??????
    GPIO_MODE_AF_OD        // ??????
} GPIO_Mode_TypeDef;

// ???GPIO
void GPIO_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode);

#endif