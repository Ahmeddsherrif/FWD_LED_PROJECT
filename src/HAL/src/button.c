/**
 * @file button.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-28
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
//! \b Section1 : Private Data types
//! \b Section2 : Private Functions
//! \b Section3 : Public API Defenition 
//! \b Footer
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

//HAL
#include "button.h"

//MCAL
#include "GPIO.h"
#include "interrupts.h"

//User Defined Types
#include "types.h"

//Target Pin-out
#include "TargetConfig.h"

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

static uint8_t port_to_NVIC_map[NUMBER_OF_PORTS] = {
NVIC_GPIO_PORT_A,
NVIC_GPIO_PORT_B,
NVIC_GPIO_PORT_C,
NVIC_GPIO_PORT_D,
NVIC_GPIO_PORT_E,
NVIC_GPIO_PORT_F };

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

enumErrorState_t Button_Init(const button_t *Button) {
	GPIO_port_init(Button->ui8Port);
	NVIC_Init(port_to_NVIC_map[Button->ui8Port]);

	switch (Button->boolWhenPressed) {
	case LOW_WHEN_PRESSED:
		GPIO_pin_init(Button->ui8Port, Button->ui8Pin, INPUT_PULLUP);
		GPIO_pin_attachInterrupt(Button->ui8Port, Button->ui8Pin, FALLING_EDGE,
				Button->ptrfCallBackFunction);
		break;

	case HIGH_WHEN_PRESSED:
		GPIO_pin_init(Button->ui8Port, Button->ui8Pin, INPUT_PULLDOWN);
		GPIO_pin_attachInterrupt(Button->ui8Port, Button->ui8Pin, RISING_EDGE,
				Button->ptrfCallBackFunction);
		break;
	}

	return NO_ERROR;
}

enumErrorState_t Button_Current_State(const button_t *Button,
		 bool *boolPtrButtonState) {

	bool buttonValue;
	GPIO_pin_read(Button->ui8Port, Button->ui8Pin, &buttonValue);

	switch (Button->boolWhenPressed) {
	case LOW_WHEN_PRESSED:

		switch (buttonValue) {
		case LOW:
			*boolPtrButtonState = PRESSED;
			break;

		case HIGH:
			*boolPtrButtonState = NOT_PRESSED;
			break;
		}

		break;

	case HIGH_WHEN_PRESSED:

		switch (buttonValue) {
		case LOW:
			*boolPtrButtonState = NOT_PRESSED;
			break;

		case HIGH:
			*boolPtrButtonState = PRESSED;
			break;
		}

		break;
	}

	return NO_ERROR;
}

//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************
