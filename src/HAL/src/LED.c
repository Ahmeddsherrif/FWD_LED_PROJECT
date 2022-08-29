/**
 * @file LED.c
 * @author AHMED SHERIF (ahmedselfiky11@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-29
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
#include <stdint.h>

#include "LED.h"

#include "GPIO.h"
#include "systimer.h"

#include "types.h"

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

#define MAX_NUMBER_OF_BLINKS                    ((uint8_t) 5)
#define MIN_NUMBER_OF_BLINKS                    ((uint8_t) 1)

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

enumErrorState_t LED_Init(const LED_t *inputLED) {
	GPIO_port_init(inputLED->ledPort);
	GPIO_pin_init(inputLED->ledPort, inputLED->ledPin, OUTPUT_2mA);

	return NO_ERROR;
}

enumErrorState_t LED_ON(const LED_t *inputLED) {
	GPIO_pin_write(inputLED->ledPort, inputLED->ledPin, HIGH);

	return NO_ERROR;
}

enumErrorState_t LED_OFF(const LED_t *inputLED) {
	GPIO_pin_write(inputLED->ledPort, inputLED->ledPin, LOW);

	return NO_ERROR;
}

enumErrorState_t LED_FLIP(const LED_t *inputLED) {
	GPIO_pin_toggle(inputLED->ledPort, inputLED->ledPin);

	return NO_ERROR;
}

enumErrorState_t LED_Indicate(const LED_t *inputLED,
		const uint8_t numberOfBlinks, const uint32_t onDuration,
		const uint32_t offDuration) {

	if (numberOfBlinks < MIN_NUMBER_OF_BLINKS
			|| numberOfBlinks > MAX_NUMBER_OF_BLINKS) {
		return WRONG_NUMBER_OF_BLINKS;
	}

	uint8_t i;
	for (i = 0; i < numberOfBlinks; i++) {
		GPIO_pin_write(inputLED->ledPort, inputLED->ledPin, HIGH);
		delay_ms(onDuration);
		GPIO_pin_write(inputLED->ledPort, inputLED->ledPin, LOW);
		delay_ms(offDuration);
	}

	return NO_ERROR;
}

//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************
