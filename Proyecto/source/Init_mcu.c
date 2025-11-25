#include "config.h"

void init_mcu(void)
{
    GpioInitStructure_AVR Entradas, Salidas, Ultrasonico;

    // ----- ENTRADAS -----
    Entradas.modo  = avr_GPIO_mode_Input;
    Entradas.port  = E_PORT;
    Entradas.pines = E1_MASK | E2_MASK | E3_MASK;
    init_gpio(Entradas);

    // ----- SALIDAS -----
    Salidas.modo  = avr_GPIO_mode_Output;
    Salidas.port  = S_PORT;
    Salidas.pines = S1_MASK | S2_MASK | S3_MASK;
    init_gpio(Salidas);


    // --- TRIGGER como salida ---
    Ultrasonico.port  = TRIG_PORT;
    Ultrasonico.modo  = avr_GPIO_mode_Output;
    Ultrasonico.pines = TRIG_MASK;
    init_gpio(Ultrasonico);

    // --- ECHO como entrada ---
    Ultrasonico.port  = ECHO_PORT;
    Ultrasonico.modo  = avr_GPIO_mode_Input;
    Ultrasonico.pines = ECHO_MASK;
    init_gpio(Ultrasonico);
    
   }