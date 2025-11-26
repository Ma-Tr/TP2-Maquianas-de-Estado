#include "config.h"

void init_mcu(void)
{
    GpioInitStructure_AVR ENTRADAS, SALIDAS, ULTRASONICO;

    // ----- ENTRADAS -----
    ENTRADAS.modo  = avr_GPIO_mode_Input;
    ENTRADAS.port  = E_PORT;
    ENTRADAS.pines = E1_MASK | E2_MASK | E3_MASK;
    init_gpio(ENTRADAS);

    // ----- SALIDAS -----
    SALIDAS.modo  = avr_GPIO_mode_Output;
    SALIDAS.port  = S_PORT;
    SALIDAS.pines = LLENADO_MASK | VACIADO_MASK | S3_MASK;
    init_gpio(SALIDAS);


    // --- TRIGGER como salida ---
    ULTRASONICO.port  = TRIG_PORT;
    ULTRASONICO.modo  = avr_GPIO_mode_Output;
    ULTRASONICO.pines = TRIG_MASK;
    init_gpio(ULTRASONICO);

    // --- ECHO como entrada ---
    ULTRASONICO.port  = ECHO_PORT;
    ULTRASONICO.modo  = avr_GPIO_mode_Input;
    ULTRASONICO.pines = ECHO_MASK;
    init_gpio(ULTRASONICO);
    
   }
int contador;

long medir_distancia_cm(void)
{
    uint32_t tiempo = 0;

    // === 1) Pulso de TRIGGER 10 us ===
    clear_pin(TRIG, TRIG_MASK);
    _delay_us(2);
    set_pin(TRIG, TRIG_MASK);
    _delay_us(10);
    clear_pin(TRIG, TRIG_MASK);

    // === 2) Esperar que ECHO pase a alto (con timeout) ===
    uint32_t contador_timeout = 0;
    while(ECHO == 0) {
        _delay_us(1);
        contador_timeout++;

        if (contador_timeout > TIMEOUT_US) {
            return 0;   // no hubo eco
        }
    }

    // === 3) Contar cuanto tiempo ECHO permanece en alto ===
    tiempo = 0;
    while(ECHO == 1) {
        _delay_us(1);
        tiempo++;

        if (tiempo > TIMEOUT_US) {
            return 0;  // eco demasiado largo
        }
    }

    // === 4) Convertir tiempo a distancia en cm ===
    return (uint16_t)(tiempo / 58);
}

