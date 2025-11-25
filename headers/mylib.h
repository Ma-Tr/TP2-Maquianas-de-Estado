#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>



//CONSTANTES//

#define TIMEOUT_US 30000 

//VARIABLES//

typedef enum {
    ESPERA = 0,
    LLENAR = 1,
    VACIAR = 2
} Estados_t;



typedef struct {
   char N;
   char Set_N;
   char Delta_N;
} nivel_t;

// FUNCIONES//
void init_mcu(void);
void mySystick(void);
long medir_distancia_cm(void);
void interrupcionExternas(void);

//FUNCIONES ESTADOS//
Estados_t f_Espera(nivel_t nivel);
Estados_t f_Llenar(nivel_t nivel);
Estados_t f_Vaciar(nivel_t nivel);


#endif