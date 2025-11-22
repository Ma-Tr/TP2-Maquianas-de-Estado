#ifndef CONFIG_H
#define CONFIG_H 1
#include <util/delay.h>
#include "avr_api.h"

int CM;

#define Set_N 28
int Delta_N = 10;
int Nivel = 0;
char Estado = 1;

void init_mcu(void);
void mySystick(void);
long medir_distancia_cm(void);
void interrupcionExternas(void);

#define TIMEOUT_US 30000
// =========================
//  ENTRADAS  (Puerto D)
// =========================

#define E_PORT avr_GPIO_D
	
#define E1        avr_GPIOD_IN_0
#define E1_MASK   avr_GPIO_PIN_0

#define E2        avr_GPIOD_IN_1
#define E2_MASK   avr_GPIO_PIN_1

#define E3        avr_GPIOD_IN_2
#define E3_MASK   avr_GPIO_PIN_2

// =========================
//  SALIDAS (Puerto B)
// =========================

#define S_PORT avr_GPIO_B

#define S1        avr_GPIOB_OUT_0
#define S1_MASK   avr_GPIO_PIN_0

#define S2        avr_GPIOB_OUT_1
#define S2_MASK   avr_GPIO_PIN_1

#define S3        avr_GPIOB_OUT_2
#define S3_MASK   avr_GPIO_PIN_2

// =========================
//  Ultrasonico (Puerto E)
// =========================
// Puerto del TRIGGER ? salida
#define TRIG_PORT   avr_GPIO_E
#define TRIG        avr_GPIOE_OUT_0
#define TRIG_MASK   avr_GPIO_PIN_0

// Puerto del ECHO ? entrada
#define ECHO_PORT   avr_GPIO_E
#define ECHO        avr_GPIOE_IN_1
#define ECHO_MASK   avr_GPIO_PIN_1


#endif
