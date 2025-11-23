#include "config.h"

Estados_t f_Llenar(Nivel_t nivel) {
    Llenado = 1;
    Vaciado = 0;

    nivel.N = medir_distancia_cm();

    if (nivel.N < nivel.Set_N)
        return Espera; // como la distancia es mucha a la altura que queremos, llenamos
    else
        return Llenar; // la altura del agua llego al nivel que queremos
}

