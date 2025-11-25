#include "config.h"
int main(void)
{
   init_mcu();

   nivel_t nivel = { 
       .N = 0,
       .Set_N = 28,
       .Delta_N = 10
   };

   Estados_t estado = ESPERA; //seteo el estado inicial

    while(1)
    {
        switch(estado)
        {
            case ESPERA:
                estado = f_Espera(nivel);
                break;

            case LLENAR:
                estado = f_Llenar(nivel);
                break;

            case VACIAR:
                estado = f_Vaciar(nivel);
                break;
        }
	

    }
}
