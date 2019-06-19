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

DEBUG_DEFINITION debug_data[DEBUG_DATA_COUNT]= {
		DEBUG_INIT_VALUE,
		DEBUG_INIT_VALUE,
		DEBUG_INIT_VALUE,
		DEBUG_INIT_VALUE,
		DEBUG_INIT_VALUE,
		DEBUG_INIT_VALUE,
};

uint8_t debug_index = 0;
uint8_t data_sizes[DEBUG_TYPE_NONE] = {
		1,
		1,
		2,
		2,
		4,
		4,
		4,
		8,
		0
};


void debug(char* varname, DEBUG_TYPE type, void* varpointer){
	if(debug_index + 1 < DEBUG_DATA_COUNT){
		debug_index++;
		debug_data[index].debug_type = type;
		strcpy(debug_data[index].name, varname);
		debug_data[index].pointer = &varpointer;
	}
};


void sendDebug(DEBUG_DEFINITION debug_definition){
	uint8_t uart_index = 0;
	for(uint8_t index = 0; i < DEBUG_DATA_COUNT; i++){
		if(debug_data[index].debug_type != DEBUG_TYPE_NONE){
			uint8_t data_size = data_sizes[(int)debug_data[index].debug_type];
			uart_buffer[uart_index] = (char)debug_data[index].debug_type;
		}
	}
}

/**
 * @}
 */

/**
 * @}
 */
