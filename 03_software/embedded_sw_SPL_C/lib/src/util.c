/***********************
 * @file 	util.c
 * @author	resiz, tard
 * @date	15 Mar 2019
 ************************/

#include "util.h"
#include <math.h>
#include "hw_status_led.h"

/**
 * reverses a string 'str' of length 'len'
 */
void reverse(char *str, int len) {
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

/**
 * Converts a given integer x to string str[].  d is the number
 * of digits required in output. If d is more than the number
 * of digits in x, then 0s are added at the beginning.
 */
int intToStr(int x, char str[], int d) {
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

/**
 * Converts a floating point number to string.
 */
void ftoa(float n, char *res, int afterpoint) {
	// Extract integer part
	int ipart = (int) n;

	// Extract floating part
	float fpart = n - (float) ipart;

	// convert integer part to string
	int i = intToStr(ipart, res, 0);

	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.';  // add dot

		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);

		intToStr((int) fpart, res + i + 1, afterpoint);
	}
}

/**
 *  it is the caller's responsibility to provide a sufficient buffer!
 */
void ToBytes(void *dataIn, uint8_t size, uint8_t dataOut[]) {
	for (uint8_t i = 0; i < size; i++) {
		dataOut[i] = (uint8_t) (((*((uint32_t*) dataIn)) >> (size - 1 - i))
				&& 0xFF);
	}
}

/**
 * @brief Initialize SysTick Timer
 * how often the IRQ called
 */
void initSysTick() {

	RCC_ClocksTypeDef clockStruct;
	RCC_GetClocksFreq(&clockStruct);

	SysTick_Config(
			clockStruct.HCLK_Frequency / SYS_TICK_CLKSOURCE_DIV_VALUE
					/ 1000*SYS_TICK_PERIOD_ms); /*160MHz/8/1000 -> 1ms */

	/*160MHz/8 = 20MHz*/
	SysTick_CLKSourceConfig(SYS_TICK_CLKSOURCE_DIV);
	/* Configure the SysTick handler priority */
//	NVIC_SetPriority(SysTick_IRQn, 0x0);
}

__IO uint32_t systick_cnt = 0;
__IO uint32_t time_out = 0x0;

/**
 * @brief Set the timeout value
 * @param ms millisecond
 */
void setTimeOut_ms(uint32_t ms) {
	time_out = ms;
}

uint32_t getTimeOut_ms() {
	return time_out;
}

void SysTick_Handler() {

	/* Decrement the time out value */
	if (time_out != 0x0) {
		time_out--;
	}

	systick_cnt++;
	if (systick_cnt % HEARTBEAT_TOGGLE_PERIOD_ms == 0) {
		toggleLED(HEARTBEAT);
	}
}

/**
 * @breif delay with polling
 * @param wait_ms milliseconds to wait
 */
void delay_ms(uint32_t wait_ms) {
	uint32_t current_ms = systick_cnt;
	uint32_t next_ms;

	/* check if it will overflow*/
	if ((UINT32_MAX - wait_ms) < current_ms) {
		next_ms = wait_ms - (UINT32_MAX - current_ms);
	} else {
		next_ms = current_ms + wait_ms;
	}

	while (next_ms != systick_cnt)
		;
}
