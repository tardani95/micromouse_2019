/***********************
 * @file 	util.h
 * @author	resiz,tard
 * @date	15 Mar 2019
 ************************/
#ifndef UTIL_H_
#define UTIL_H_

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"

#define HEARTBEAT_TOGGLE_PERIOD_ms		1000
#define SYS_TICK_PERIOD_ms				1
#define SYS_TICK_CLKSOURCE_DIV 			SysTick_CLKSource_HCLK_Div8
#define SYS_TICK_CLKSOURCE_DIV_VALUE 	8

#define USER_TIMEOUT_ms					20

void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char *res, int afterpoint);
void ToBytes(void *dataIn, uint8_t size, uint8_t *dataOut);

void initSysTick(void);
void setTimeOut_ms(uint32_t millisecond);
uint32_t getTimeOut_ms(void);
void SysTick_Handler(void);
void delay_ms(uint32_t milliseconds);

#endif /* INC_UTIL_H_ */
