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

/* string size max 50 char! */
void sendToPC(Target target, char *verbosity, char *src, char *msg){
	/*Tell PC the target of the message*/
	BTSendChar(target);

	/*Send verbosity of message*/
	strcpy(uart_buffer, verbosity);
	strcat(uart_buffer, ": ");
	BTSendString(uart_buffer);

	/*Send name of message source file*/
	strcpy(uart_buffer, src);
	strcat(uart_buffer, ": ");
	BTSendString(uart_buffer);

	/*Send message*/
	strcpy(uart_buffer, msg);
	strcat(uart_buffer, "\n");
	BTSendString(uart_buffer);

	/*send end of transition character*/
	BTSendChar(23);

}

void consoleSend(char *msg){
	BTSendString(msg);
}

/**
 * @}
 */

/**
 * @}
 */
