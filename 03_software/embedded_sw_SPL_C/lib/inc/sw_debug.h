/***********************
 * @file 	sw_debug.h
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#ifndef SW_DEBUG_H_
#define SW_DEBUG_H_

#include <string.h>
#include "stm32f4xx.h"


/** @addtogroup software_modules
 * @{
 */

/** @addtogroup DBG
 * @{
 */

#define MAX_STRING_SIZE 50

extern char uart_buffer[MAX_STRING_SIZE];

/*PC application targets*/
typedef enum{
	Console,
	MATLAB,
	Unknown
}Target;

#define __FILE_PATH__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/*macros for sending to Console*/
#define DEBUG(msg) 	 (sendToPC(Console, "DEBUG",   __FILE_PATH__, msg))
#define ERROR(msg) 	 (sendToPC(Console, "ERROR",   __FILE_PATH__, msg))
#define WARNING(msg) (sendToPC(Console, "WARNING", __FILE_PATH__, msg))
#define INFO(msg)	 (sendToPC(Console, "INFO",    __FILE_PATH__, msg))
#define SEND(msg)	 (consoleSend(msg))

/*macro for sending to matlab*/
#define MATSEND(msg) (sendToPC(MATLAB, "THIS IS MATLAB!!!", __FILE_PATH__,   msg))


/*#define DEBUG(msg) 	 (consoleWrite("", "",   msg))
#define INFO(msg) 	 (consoleWrite("", "",   msg))*/

typedef enum{
	DEBUG_TYPE_UINT8,
	DEBUG_TYPE_INT8,
	DEBUG_TYPE_UINT16,
	DEBUG_TYPE_INT16,
	DEBUG_TYPE_UINT32,
	DEBUG_TYPE_INT32,
	DEBUG_TYPE_FLOAT,
	DEBUG_TYPE_DOUBLE,
	DEBUG_TYPE_NONE
}DEBUG_TYPE;

#define DEBUG_NAME_MAX_LENGTH 15
#define DEBUG_DATA_COUNT 6

typedef struct{
	DEBUG_TYPE debug_type;
	char name[DEBUG_NAME_MAX_LENGTH];
	void* pointer;
}DEBUG_DEFINITION;

#define DEBUG_INIT_VALUE {				\
		.debug_type = DEBUG_TYPE_NONE,	\
		.name = "undefined",			\
		.pointer = NULL					\
	}

/*#define allow_debug()						\
	DEBUG_DEFINITION debug_data_##__FILE_PATH__[DEBUG_DATA_PER_FILE]= { \
		DEBUG_INIT_VALUE, \
		DEBUG_INIT_VALUE, \
		DEBUG_INIT_VALUE, \
		DEBUG_INIT_VALUE, \
		DEBUG_INIT_VALUE, \
		DEBUG_INIT_VALUE, \
}*/


/*#define debug(index, varname, type, variable)					\
	debug_data_##__FILE_PATH__[index].debug_type = type;		\
	strcpy(debug_data_##__FILE_PATH__[index].name, #varname);	\
	debug_data_##__FILE_PATH__[index].pointer = &variable
*/



void debug(char* varname, DEBUG_TYPE type, void* varpointer);
void sendDebug(DEBUG_DEFINITION debug_definition);


void sendToPC(Target target, char *verbosity, char *src, char *msg);
void consoleSend(char *msg);
void waitForAck(void);

/**
 * @}
 */

/**
 * @}
 */

#endif /* SW_DEBUG_H_ */
