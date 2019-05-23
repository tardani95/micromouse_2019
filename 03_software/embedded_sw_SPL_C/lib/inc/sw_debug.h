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
