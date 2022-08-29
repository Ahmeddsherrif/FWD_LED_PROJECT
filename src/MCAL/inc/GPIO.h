/**
 * @file GPIO.h
 * @author AHMED SHERIF (ahmedselfiky11@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
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
//! \b Section1 : Private MACROS
//! \b Section2 : Public API Definitions
//! \b Footer
//*******************************************************************************************************************************

#ifndef _DRIVERS_GPIO_H_
#define _DRIVERS_GPIO_H_

//*******************************************************************************************************************************
//
// db   db d88888b  .d8b.  d8888b. d88888b d8888b. 
// 88   88 88'     d8' `8b 88  `8D 88'     88  `8D 
// 88ooo88 88ooooo 88ooo88 88   88 88ooooo 88oobY' 
// 88~~~88 88~~~~~ 88~~~88 88   88 88~~~~~ 88`8b   
// 88   88 88.     88   88 88  .8D 88.     88 `88. 
// YP   YP Y88888P YP   YP Y8888D' Y88888P 88   YD                                                                                                
//
//*******************************************************************************************************************************

#include <stdint.h>
#include <stdbool.h>

#include "types.h"

#include "TargetConfig.h"
#include "TM4C123GH6PM.h"

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

#define OUTPUT_2mA          ((uint8_t) 0)
#define OUTPUT_4mA          ((uint8_t) 1)
#define OUTPUT_8mA          ((uint8_t) 2)
#define INPUT_OPEN_DRAIN    ((uint8_t) 3)
#define INPUT_PULLUP        ((uint8_t) 4)
#define INPUT_PULLDOWN      ((uint8_t) 5)

#define LOW                 ((bool) false)
#define HIGH                ((bool) true)

#define RISING_EDGE          ((uint8_t) 0)
#define FALLING_EDGE         ((uint8_t) 1)
#define BOTH_EDGES           ((uint8_t) 2)
#define HIGH_LEVEL           ((uint8_t) 3)
#define LOW_LEVEL            ((uint8_t) 4)

//*******************************************************************************************************************************
//
// .d8888. d88888b  .o88b. d888888b d888888b  .d88b.  d8b   db     .d888b. 
// 88'  YP 88'     d8P  Y8 `~~88~~'   `88'   .8P  Y8. 888o  88     VP  `8D 
// `8bo.   88ooooo 8P         88       88    88    88 88V8o 88        odD' 
//   `Y8b. 88~~~~~ 8b         88       88    88    88 88 V8o88      .88'   
// db   8D 88.     Y8b  d8    88      .88.   `8b  d8' 88  V888     j88.    
// `8888Y' Y88888P  `Y88P'    YP    Y888888P  `Y88P'  VP   V8P     888888D 
//
//*******************************************************************************************************************************

enumErrorState_t GPIO_port_init(const uint8_t ui8Port);
enumErrorState_t GPIO_pin_init(const uint8_t ui8Port, const uint8_t ui8Pin,
		const uint8_t ui8Direction);
enumErrorState_t GPIO_pin_write(const uint8_t ui8Port, const uint8_t ui8Pin,
		bool ui8DigitalValue);
enumErrorState_t GPIO_pin_toggle(const uint8_t ui8Port, const uint8_t ui8Pin);
enumErrorState_t GPIO_pin_read(const uint8_t ui8Port, const uint8_t ui8Pin,
		bool *boolPtrResult);
enumErrorState_t GPIO_pin_attachInterrupt(const uint8_t ui8Port,
		const uint8_t ui8Pin, const uint8_t ui8TriggerMode,
		void (*ptrfCallbackFunc)());

//*******************************************************************************************************************************
//
//  d88888b  .d88b.   .d88b.  d888888b d88888b d8888b. 
//  88'     .8P  Y8. .8P  Y8. `~~88~~' 88'     88  `8D 
//  88ooo   88    88 88    88    88    88ooooo 88oobY' 
//  88~~~   88    88 88    88    88    88~~~~~ 88`8b   
//  88      `8b  d8' `8b  d8'    88    88.     88 `88. 
//  YP       `Y88P'   `Y88P'     YP    Y88888P 88   YD 
//
//*******************************************************************************************************************************

#endif  //_DRIVERS_GPIO_H_

//*******************************************************************************************************************************
// END OF FILE  
//*******************************************************************************************************************************
