#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>



//CONSTANTES//

#define TIMEOUT_US 30000 

//VARIABLES//

typedef enum {
    Espera = 0,
    Llenar = 1,
    Vaciar = 2
} Estados_t;



typedef struct {
   char N;
   char Set_N;
   char Delta_N;
} Nivel_t;

// FUNCIONES//
void init_mcu(void);
void mySystick(void);
long medir_distancia_cm(void);
void interrupcionExternas(void);

//FUNCIONES ESTADOS//
Estados_t f_Espera(Nivel_t nivel);
Estados_t f_Llenar(Nivel_t nivel);
Estados_t f_Vaciar(Nivel_t nivel);


#endif