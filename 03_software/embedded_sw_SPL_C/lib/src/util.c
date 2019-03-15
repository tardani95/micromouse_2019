/***********************
 * @file 	util.c
 * @author	resiz
 * @date	15 Mar 2019
 ************************/

#include "util.h"
#include <math.h>
#include "hw_status_led.h"

// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

// Converts a floating point number to string.
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

void initSysTick(void){
	//TODO clksourceconfig has no effect
	SysTick_CLKSourceConfig(SYS_TICK_CLKSOURCE_DIV); /*168MHz/8 = 21MHz*/
	SystemCoreClockUpdate();

	RCC_ClocksTypeDef clockStruct;
	RCC_GetClocksFreq(&clockStruct);
	//TODO timer period is not accurate
	SysTick_Config(	clockStruct.SYSCLK_Frequency/SYS_TICK_CLKSOURCE_DIV_VALUE/SYS_TICK_FREQ_HZ - 12); /*21000/21MHz = 1ms*/

}

volatile uint32_t systick_cnt = 0;

void SysTick_Handler(void){
	systick_cnt++;
	if(systick_cnt%1000 == 0){
		toggleLED(HEARTBEAT);
	}
}
