/***********************
 * @file 	sw_debug.c
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#include "sw_debug.h"
#include "hw_BT_module.h"
#include <string.h>

/** @addtogroup software_modules
 * @{
 */

/** @defgroup DBG	Debug
 * @{
 */

char uart_buffer[MAX_STRING_SIZE] = { "\0" };

/* string size max 100 char! */
void consoleWrite(char *filename, char *dbg_cat, char *msg){

	/*Send name of message source file*/
	strcpy(uart_buffer, filename);
	strcat(uart_buffer, ": ");
	BTSendString(uart_buffer);

	/*Send category of message source*/
	strcpy(uart_buffer, dbg_cat);
	strcat(uart_buffer, ": ");
	BTSendString(uart_buffer);

	/*Send message*/
	strcpy(uart_buffer, msg);
	strcat(uart_buffer, "\n");
	BTSendString(uart_buffer);

}

//TODO user code here
/**
 * @}
 */

/**
 * @}
 */
