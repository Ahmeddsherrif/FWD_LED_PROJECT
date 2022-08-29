/**
 * @file types.h
 * @author AHMED SHERIF (ahmedselfiky11@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright FWD_Advanced(c) 2022
 * 
 */

//*******************************************************************************************************************************
//
//  .o88b.  .d88b.  d8b   db d888888b d88888b d8b   db d888888b .d8888. 
// d8P  Y8 .8P  Y8. 888o  88 `~~88~~' 88'     888o  88 `~~88~~' 88'  YP 
// 8P      88    88 88V8o 88    88    88ooooo 88V8o 88    88    `8bo.   
// 8b      88    88 88 V8o88    88    88~~~~~ 88 V8o88    88      `Y8b. 
// Y8b  d8 `8b  d8' 88  V888    88    88.     88  V888    88    db   8D 
//  `Y88P'  `Y88P'  VP   V8P    YP    Y88888P VP   V8P    YP    `8888Y'                                                                                                
//
//*******************************************************************************************************************************
//! \b Header
//! \b Section1 : User Defined Data types
//! \b Footer
//*******************************************************************************************************************************

#ifndef _TYPES_H_
#define _TYPES_H_


//*******************************************************************************************************************************
//
// .d8888. d88888b  .o88b. d888888b d888888b  .d88b.  d8b   db      db 
// 88'  YP 88'     d8P  Y8 `~~88~~'   `88'   .8P  Y8. 888o  88     o88 
// `8bo.   88ooooo 8P         88       88    88    88 88V8o 88      88 
//   `Y8b. 88~~~~~ 8b         88       88    88    88 88 V8o88      88 
// db   8D 88.     Y8b  d8    88      .88.   `8b  d8' 88  V888      88 
// `8888Y' Y88888P  `Y88P'    YP    Y888888P  `Y88P'  VP   V8P      VP 
//
//*******************************************************************************************************************************
typedef enum {
	WRONG_PORT_NUMBER,
	WRONG_PIN_NUMBER,
	WRONG_PIN_DIRECTION,
	WRONG_DIGITAL_VALUE,
	WRONG_VECTOR_NUMBER,
	WRONG_TRIGGER_MODE,
	WRONG_NUMBER_OF_BLINKS,
	NO_ERROR
} enumErrorState_t;

#endif //_TYPES_H_

//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************