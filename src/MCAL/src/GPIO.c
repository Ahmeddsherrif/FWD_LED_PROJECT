/**
 * @file GPIO.c
 * @author AHMED SHERIF (ahmedselfiky11@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright ADVANCED_FWD(c) 2022
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
//! \b Section1 : PRIVATE MACROS
//! \b Section2 : PRIVATE Functions
//! \b Section3 : PUBLIC API DEFENETIONS
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

//STD Types
#include <stdint.h>
#include <stdbool.h>

//MCAL
#include "GPIO.h"

//Target Specific
#include "TM4C123GH6PM.h"
#include "TargetConfig.h"

//user defined types
#include "types.h"

//Helper Functions
#include "bitmath.h"

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

#define OPEN_SESAME             			((uint32_t) 0x4C4F434B)

#define BIT_0       					    ((uint32_t) 0x00000001)
#define BIT_1       					    ((uint32_t) 0x00000002)
#define BIT_2       					    ((uint32_t) 0x00000004)
#define BIT_3       					    ((uint32_t) 0x00000008)
#define BIT_4       					    ((uint32_t) 0x00000010)
#define BIT_5       					    ((uint32_t) 0x00000020)
#define BIT_6       					    ((uint32_t) 0x00000040)
#define BIT_7       					    ((uint32_t) 0x00000080)

#define REGISTER_CONCAT(PORT_OFFSET, REGISTER_OFFSET) (*((volatile uint32_t *)(GPIO_PORT_A_BASE + PORT_OFFSET + REGISTER_OFFSET)))



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

//Two_Diemensional Array of pointer to functions
static void (*ptrf[NUMBER_OF_PORTS][NUMBER_OF_PINS])();

static uint32_t port_to_offset_map[NUMBER_OF_PORTS] = {
GPIO_PORT_A_OFFSET,
GPIO_PORT_B_OFFSET,
GPIO_PORT_C_OFFSET,
GPIO_PORT_D_OFFSET,
GPIO_PORT_E_OFFSET,
GPIO_PORT_F_OFFSET };

void GPIO_Port_X_Handler_Map(const uint8_t ui8Port) {

	switch (REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_MIS_OFFSET)) {
	case BIT_0:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_0);
		(ptrf[ui8Port][PIN_0])();
		break;

	case BIT_1:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_1);
		(ptrf[ui8Port][PIN_1])();
		break;

	case BIT_2:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_2);
		(ptrf[ui8Port][PIN_2])();
		break;

	case BIT_3:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_3);
		(ptrf[ui8Port][PIN_3])();
		break;

	case BIT_4:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_4);
		(ptrf[ui8Port][PIN_4])();
		break;

	case BIT_5:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_5);
		(ptrf[ui8Port][PIN_5])();
		break;

	case BIT_6:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_6);
		(ptrf[ui8Port][PIN_6])();
		break;

	case BIT_7:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ICR_OFFSET),
				PIN_7);
		(ptrf[ui8Port][PIN_7])();
		break;
	}
}


//NVIC Handlers

void GPIO_PortA_Handler(void) {
	GPIO_Port_X_Handler_Map(PORT_A);
}

void GPIO_PortB_Handler(void) {
	GPIO_Port_X_Handler_Map(PORT_B);
}

void GPIO_PortC_Handler(void) {
	GPIO_Port_X_Handler_Map(PORT_C);
}

void GPIO_PortD_Handler(void) {
	GPIO_Port_X_Handler_Map(PORT_D);
}

void GPIO_PortE_Handler(void) {
	GPIO_Port_X_Handler_Map(PORT_E);
}

void GPIO_PortF_Handler(void) {
	GPIO_Port_X_Handler_Map(PORT_F);
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
 * @param portOffset
 * @return enumErrorState_t 
 */
enumErrorState_t GPIO_port_init(const uint8_t ui8Port) {

	if (ui8Port >= NUMBER_OF_PORTS) {
		return WRONG_PORT_NUMBER;
	}

	switch (port_to_offset_map[ui8Port]) {
	case GPIO_PORT_A_OFFSET:
		SET_BIT(SYSCTL_RCGCGPIO_R, SYSCTL_RCGCGPIO_BIT_R0);
		break;

	case GPIO_PORT_B_OFFSET:
		SET_BIT(SYSCTL_RCGCGPIO_R, SYSCTL_RCGCGPIO_BIT_R1);
		break;

	case GPIO_PORT_C_OFFSET:
		SET_BIT(SYSCTL_RCGCGPIO_R, SYSCTL_RCGCGPIO_BIT_R2);
		break;

	case GPIO_PORT_D_OFFSET:
		SET_BIT(SYSCTL_RCGCGPIO_R, SYSCTL_RCGCGPIO_BIT_R3);
		break;

	case GPIO_PORT_E_OFFSET:
		SET_BIT(SYSCTL_RCGCGPIO_R, SYSCTL_RCGCGPIO_BIT_R4);
		break;

	case GPIO_PORT_F_OFFSET:
		SET_BIT(SYSCTL_RCGCGPIO_R, SYSCTL_RCGCGPIO_BIT_R5);
		break;
	}

	return NO_ERROR;
}

/**
 * @brief This Function used to intialize the pin
 * 
 * @param portOffset
 * @param ui8Pin 
 * @param ui8Direction 
 * @return enumErrorState_t 
 */
enumErrorState_t GPIO_pin_init(const uint8_t ui8Port, const uint8_t ui8Pin,
		const uint8_t ui8Direction) {

	if (ui8Port >= NUMBER_OF_PORTS) {
		return WRONG_PORT_NUMBER;
	}

	if (ui8Pin >= NUMBER_OF_PINS) {
		return WRONG_PORT_NUMBER;
	}

	//TODO: Function to Check if it is from the NMI Pins
	REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_LOCK_OFFSET) =
	OPEN_SESAME;
	SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_OCR_OFFSET),
			ui8Pin);

	//Determines The Pin Direction
	switch (ui8Direction) {
	case OUTPUT_2mA:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DIR_OFFSET),
				ui8Pin);
		SET_BIT(
				REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DRIVE2_OFFSET),
				ui8Pin);
		break;

	case OUTPUT_4mA:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DIR_OFFSET),
				ui8Pin);
		SET_BIT(
				REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DRIVE4_OFFSET),
				ui8Pin);
		break;

	case OUTPUT_8mA:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DIR_OFFSET),
				ui8Pin);
		SET_BIT(
				REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DRIVE8_OFFSET),
				ui8Pin);
		break;

	case INPUT_OPEN_DRAIN:
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DIR_OFFSET),
				ui8Pin);
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_ODR_OFFSET),
				ui8Pin);
		break;

	case INPUT_PULLUP:
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DIR_OFFSET),
				ui8Pin);
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_PUR_OFFSET),
				ui8Pin);
		break;

	case INPUT_PULLDOWN:
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DIR_OFFSET),
				ui8Pin);
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_PDR_OFFSET),
				ui8Pin);
		break;

	default:
		return WRONG_PIN_DIRECTION;
	}

	//Enable The Digital Function for the corrisponding pin
	SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DEN_OFFSET),
			ui8Pin);

	return NO_ERROR;
}

/**
 * @brief 
 * 
 * @param portOffset
 * @param ui8Pin 
 * @param ui8DigitalValue 
 * @return enumErrorState_t 
 */
enumErrorState_t GPIO_pin_write(const uint8_t ui8Port, const uint8_t ui8Pin,
bool ui8DigitalValue) {

	if (ui8Port >= NUMBER_OF_PORTS) {
		return WRONG_PORT_NUMBER;
	}

	if (ui8Pin >= NUMBER_OF_PINS) {
		return WRONG_PORT_NUMBER;
	}

	//TODO: check if the pin is output not an input

	switch (ui8DigitalValue) {
	case HIGH:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DATA_OFFSET),
				ui8Pin);
		break;

	case LOW:
		CLEAR_BIT(
				REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DATA_OFFSET),
				ui8Pin);
		break;

	default:
		return WRONG_DIGITAL_VALUE;
	}

	return NO_ERROR;
}

/**
 * @brief 
 * 
 * @param portOffset
 * @param ui8Pin 
 * @return enumErrorState_t 
 */
enumErrorState_t GPIO_pin_toggle(const uint8_t ui8Port, const uint8_t ui8Pin) {

	if (ui8Port >= NUMBER_OF_PORTS) {
		return WRONG_PORT_NUMBER;
	}

	if (ui8Pin >= NUMBER_OF_PINS) {
		return WRONG_PORT_NUMBER;
	}

	//TODO: check if the pin is output not an input

	TOGGLE_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DATA_OFFSET),
			ui8Pin);

	return NO_ERROR;
}

/**
 * @brief 
 * 
 * @param portOffset
 * @param ui8Pin 
 * @param boolPtrResultValue 
 * @return enumErrorState_t 
 */
enumErrorState_t GPIO_pin_read(const uint8_t ui8Port, const uint8_t ui8Pin,
bool *boolPtrResultValue) {

	if (ui8Port >= NUMBER_OF_PORTS) {
		return WRONG_PORT_NUMBER;
	}

	if (ui8Pin >= NUMBER_OF_PINS) {
		return WRONG_PORT_NUMBER;
	}

	*boolPtrResultValue = (bool) GET_BIT(
			REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_DATA_OFFSET),
			ui8Pin);

	return NO_ERROR;
}

enumErrorState_t GPIO_pin_attachInterrupt(const uint8_t ui8Port,
		const uint8_t ui8Pin, const uint8_t ui8TriggerMode,
		void (*ptrfCallbackFunc)()) {

	if (ui8Port >= NUMBER_OF_PORTS) {
		return WRONG_PORT_NUMBER;
	}

	if (ui8Pin >= NUMBER_OF_PINS) {
		return WRONG_PORT_NUMBER;
	}

	switch (ui8TriggerMode) {
	case RISING_EDGE:
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IS_OFFSET),
				ui8Pin); //The edge on the corresponding pin is detected (edge-sensitive).
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IEV_OFFSET),
				ui8Pin);
		break;

	case FALLING_EDGE:
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IS_OFFSET),
				ui8Pin); //The edge on the corresponding pin is detected (edge-sensitive).
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IEV_OFFSET),
				ui8Pin);
		break;

	case BOTH_EDGES:
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IS_OFFSET),
				ui8Pin); //The edge on the corresponding pin is detected (edge-sensitive).
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IBE_OFFSET),
				ui8Pin);
		break;

	case HIGH_LEVEL:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IS_OFFSET),
				ui8Pin); //The level on the corresponding pin is detected (level-sensitive).
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IEV_OFFSET),
				ui8Pin);
		break;

	case LOW_LEVEL:
		SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IS_OFFSET),
				ui8Pin); //The level on the corresponding pin is detected (level-sensitive).
		CLEAR_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IEV_OFFSET),
				ui8Pin);
		break;

	default:
		return WRONG_TRIGGER_MODE;

	}

	SET_BIT(REGISTER_CONCAT(port_to_offset_map[ui8Port], GPIO_IM_OFFSET),
			ui8Pin);

	ptrf[ui8Port][ui8Pin] = ptrfCallbackFunc;

	return NO_ERROR;
}

//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************
