/**
 * @file systimer.h
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
//! \b Section1 : PUBLIC API DECLERATION
//! \b Footer
//*******************************************************************************************************************************

#ifndef _SYSTIMER_H_
#define _SYSTIMER_H_

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

void systimer_init(void);
void delay_ms(uint32_t time_in_ms);

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

#endif  //_SYSTIMER_H_

//*******************************************************************************************************************************
// END OF FILE
//*******************************************************************************************************************************
