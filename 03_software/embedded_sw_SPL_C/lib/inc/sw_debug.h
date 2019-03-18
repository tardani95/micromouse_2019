/***********************
 * @file 	sw_debug.h
 * @author	resiz
 * @date	Mar 14, 2019
 ************************/

#ifndef SW_DEBUG_H_
#define SW_DEBUG_H_

#include <string.h>

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup DBG
 * @{
 */

#define MAX_STRING_SIZE 50

extern char uart_buffer[MAX_STRING_SIZE];

#define __FILE_PATH__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)


#define DEBUG(msg) 	 (consoleWrite(__FILE_PATH__, "DEBUG",   msg))
#define ERROR(msg) 	 (consoleWrite(__FILE_PATH__, "ERROR",   msg))
#define WARNING(msg) (consoleWrite(__FILE_PATH__, "WARNING", msg))
#define INFO(msg)	 (consoleWrite(__FILE_PATH__, "INFO",    msg))
#define SEND(msg)	 (consoleSend(msg))

/*#define DEBUG(msg) 	 (consoleWrite("", "",   msg))
#define INFO(msg) 	 (consoleWrite("", "",   msg))*/


void consoleWrite(char *filename, char *verbosity, char *msg);
void consoleSend(char *msg);

//TODO user code here
/**
 * @}
 */

/**
 * @}
 */

#endif /* SW_DEBUG_H_ */
