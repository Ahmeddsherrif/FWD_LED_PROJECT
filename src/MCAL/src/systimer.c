/**
 * @file systimer.c
 * @author AHMED SHERIF (ahmedselfiky11@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-8-26
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
#include <stdbool.h>


#include "systimer.h"

#include "bitmath.h"

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

#define SYS_TIMER_CLOCK             (4000000)
#define GET_RELOAD(time_in_ms)      (SYS_TIMER_CLOCK * (time_in_ms * 0.001))
#define ONE_MILLI_SECOND            ((uint8_t) 1)


static volatile uint32_t tickCount = 0;
static volatile uint32_t trigger = 0;
static volatile bool isTimerCounting;

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

/**
 * @brief 
 * 
 */
void Systick_Handler(void) {
	tickCount++;

	if (tickCount >= trigger) {
		isTimerCounting = false;
		tickCount = 0;
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

/**
 * @brief 
 * 
 */
void systimer_init(void) {
	//Reload Value
	NVIC_ST_RELOAD_R = GET_RELOAD(ONE_MILLI_SECOND); //Value to load into the SysTick Current Value (STCURRENT) register
													 //when the counter reaches 0.                                                  
	//Clock Source
	CLEAR_BIT(NVIC_ST_CTRL_R, NVIC_ST_CLCK_SRC);//Precision internal oscillator (PIOSC) divided by 4

	//Interrupt Enable
	SET_BIT(NVIC_ST_CTRL_R, NVIC_ST_INTEN); //An interrupt is generated to the NVIC when SysTick counts to 0.
}

/**
 * @brief 
 * 
 * @param time_in_ms 
 */

void delay_ms(uint32_t time_in_ms) {

	trigger = time_in_ms;
	isTimerCounting = true;

	//starts counting
	SET_BIT(NVIC_ST_CTRL_R, NVIC_ST_ENABLE);

	while (isTimerCounting);

	//stop counting
	CLEAR_BIT(NVIC_ST_CTRL_R, NVIC_ST_ENABLE);

	//reset counter
	NVIC_ST_STCURRENT = 0;
}


//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************
