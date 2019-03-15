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

#define MAX_STRING_SIZE 30

extern char uart_buffer[MAX_STRING_SIZE];

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)


#define DEBUG(msg) 	 (consoleWrite(__FILENAME__, "DEBUG",   msg))
#define ERROR(msg) 	 (consoleWrite(__FILENAME__, "ERROR",   msg))
#define WARNING(msg) (consoleWrite(__FILENAME__, "WARNING", msg))
#define INFO(msg)	 (consoleWrite(__FILENAME__, "INFO",    msg))

void consoleWrite(char *filename, char *dbg_cat, char *msg);


//TODO user code here
/**
 * @}
 */

/**
 * @}
 */

#endif /* SW_DEBUG_H_ */
