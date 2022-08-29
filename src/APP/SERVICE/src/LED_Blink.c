/**
 * @file userInterface.c
 * @author AHMED SHERIF (ahmedselfiky11@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-27
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
//! \b Section1 : RCC PERIPHRALS
//! \b Section2 : GPIO PERIPHRALS
//! \b Section3 : CORTEX-M4 Periphrals
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

//STD types
#include <stdbool.h>
#include <stdint.h>

#include "LED_Blink.h"

//HAL Layers
#include "LED.h"
#include "button.h"

//MCAL Layer
#include "systimer.h"


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

#define ONE_SECOND 					((uint32_t) 1000)
#define INDICATOR_ON_TIME           ((uint32_t) 500)
#define INDICATOR_OFF_TIME          ((uint32_t) 100)
#define CONFERMATION_TIME           ((uint32_t) 500)
#define DEBOUNCE_PERIOD             ((uint32_t) 300)

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

void SW_LEFT_Callback(void);
void SW_RIGHT_Callback(void);

static uint32_t onTime, offTime;

static volatile bool isSW1_Pressed = false;
static volatile bool isSW2_Pressed = false;
static volatile bool isSW2_EverPressed = false;

static bool isSW1_PressedOnce = false;
static bool isFirstTime = true;


const static LED_t redLED = { PORT_F, PIN_1 };
const static LED_t blueLED = { PORT_F, PIN_2 };
const static LED_t greenLED = { PORT_F, PIN_3 };

const static button_t SW1 =
		{ PORT_F, PIN_4, LOW_WHEN_PRESSED, SW_LEFT_Callback };
const static button_t SW2 =
		{ PORT_F, PIN_0, LOW_WHEN_PRESSED, SW_RIGHT_Callback };



//*******************************************************************************************************************************
//
// .d8888. d88888b  .o88b. d888888b d888888b  .d88b.  d8b   db     d8888b. 
// 88'  YP 88'     d8P  Y8 `~~88~~'   `88'   .8P  Y8. 888o  88     VP  `8D 
// `8bo.   88ooooo 8P         88       88    88    88 88V8o 88       oooY' 
//   `Y8b. 88~~~~~ 8b         88       88    88    88 88 V8o88       ~~~b. 
// db   8D 88.     Y8b  d8    88      .88.   `8b  d8' 88  V888     db   8D 
// `8888Y' Y88888P  `Y88P'    YP    Y888888P  `Y88P'  VP   V8P     Y8888P' 
//
//*******************************************************************************************************************************

void System_Init(void) {
	LED_Init(&redLED);
	LED_Init(&greenLED);
	LED_Init(&blueLED);

	Button_Init(&SW1);
	Button_Init(&SW2);

	systimer_init();
}



void Main_Application(void) {
	LED_ON(&greenLED);
	delay_ms(onTime);

	LED_OFF(&greenLED);
	delay_ms(offTime);
}




void getUserInput(void) {
	onTime = 0;
	offTime = 0;

	while (1) {

		if (isSW2_EverPressed == false) {
			LED_Indicate(&blueLED, 1, CONFERMATION_TIME, CONFERMATION_TIME);
			if (isSW1_Pressed) {
				isSW1_Pressed = false;
			}
		}

		else {
			if (isSW1_Pressed) {
				isSW1_Pressed = false;
				if (isSW1_PressedOnce == false) {
					isSW1_PressedOnce = true;
				}

				if (isFirstTime) {
					onTime += ONE_SECOND;
					LED_Indicate(&blueLED, 1, INDICATOR_ON_TIME,
					INDICATOR_OFF_TIME);
				} else {
					offTime += ONE_SECOND;
					LED_Indicate(&blueLED, 1, INDICATOR_ON_TIME,
					INDICATOR_OFF_TIME);
				}
			}

			if (isSW2_Pressed) {
				isSW2_Pressed = false;
				if (isSW1_PressedOnce) {
					if (isFirstTime) {
						isFirstTime = false;
						isSW1_PressedOnce = false;
						LED_Indicate(&redLED, 1, INDICATOR_ON_TIME,
						INDICATOR_OFF_TIME);
					} else {
						LED_Indicate(&redLED, 3, CONFERMATION_TIME,
						CONFERMATION_TIME);
						//state = RUNNING;
						break;
					}
				}
			}
		}

	}
}


//*******************************************************************************************************************************
//
// .d8888. d88888b  .o88b. d888888b d888888b  .d88b.  d8b   db     d8888b. 
// 88'  YP 88'     d8P  Y8 `~~88~~'   `88'   .8P  Y8. 888o  88     VP  `8D 
// `8bo.   88ooooo 8P         88       88    88    88 88V8o 88       oooY' 
//   `Y8b. 88~~~~~ 8b         88       88    88    88 88 V8o88       ~~~b. 
// db   8D 88.     Y8b  d8    88      .88.   `8b  d8' 88  V888     db   8D 
// `8888Y' Y88888P  `Y88P'    YP    Y888888P  `Y88P'  VP   V8P     Y8888P' 
//
//*******************************************************************************************************************************

void SW_LEFT_Callback(void) {
	isSW1_Pressed = true;
}

void SW_RIGHT_Callback(void) {
	isSW2_Pressed = true;
	isSW2_EverPressed = true;
}

//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************



