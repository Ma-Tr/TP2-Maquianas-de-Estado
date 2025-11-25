#include "config.h"
int main(void)
{
   init_mcu();

   Nivel_t nivel = { 
       .N = 0,
       .Set_N = 28,
       .Delta_N = 10
   };

   Estados_t Estado = Espera; //seteo el estado inicial

    while(1)
    {
        switch(Estado)
        {
            case Espera:
                Estado = f_Espera(nivel);
                break;

            case Llenar:
                Estado = f_Llenar(nivel);
                break;

            case Vaciar:
                Estado = f_Vaciar(nivel);
                break;
        }
	

    }
}
