/**
 * @file main.c
 * @author AHMED SHERIF (ahmedselfiky11@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "LED_Blink.h"

/**
 * @brief 
 * 
 * @return int 
 */
int main(void) {

	System_Init();
	getUserInput();

	while (1) {
		Main_Application();
	}
}

//TODO: GPTM Timer activation
//TODO: interrupt instead of delay
//TODO: Switch De-bouncing

//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************
