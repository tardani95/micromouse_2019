/***********************
 * @file 	util.h
 * @author	resiz
 * @date	15 Mar 2019
 ************************/
#ifndef INC_UTIL_H_
#define INC_UTIL_H_

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"

#define SYS_TICK_PERIOD_ms	500
#define SYS_TICK_CLKSOURCE_DIV SysTick_CLKSource_HCLK
#define SYS_TICK_CLKSOURCE_DIV_VALUE 1


void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char *res, int afterpoint);
void ToBytes(void *dataIn, uint8_t size, uint8_t *dataOut);

void initSysTick(void);
void SysTick_Handler(void);

#endif /* INC_UTIL_H_ */
