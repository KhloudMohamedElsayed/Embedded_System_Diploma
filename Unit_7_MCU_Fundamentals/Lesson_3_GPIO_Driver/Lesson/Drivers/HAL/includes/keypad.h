/*
 * Keypad.h
 *
 *  Created on: Jul 28, 2022
 *      Author: KHLOUD MOHAMED
 */

#ifndef INCLUDES_KEYPAD_H_
#define INCLUDES_KEYPAD_H_

/* =========== Includes ============= */
#include "Stm32_F103C6_GPIO_Driver.h"
#include "stm32f103x6.h"

/* ========== Macros Definitions ======== */

#define KEYPAD_PORT GPIOB

// ==== ROWS OF KEYPAD ====

#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4

// ==== COLUMNS OF KEYPAD ====

#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

/* ============= Functions Prototypes ============ */

void HAL_KEYPAD_INIT(void);
char HAL_KEYPAD_GET_KEY(void);


#endif /* INCLUDES_KEYPAD_H_ */
