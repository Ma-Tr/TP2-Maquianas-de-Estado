#include "config.h"
Estados_t f_Vaciar(Nivel_t nivel) {
    Llenado = 0;
    Vaciado = 1;

    nivel.N = medir_distancia_cm();

    if (nivel.N > nivel.Set_N)
        return Espera; // como la distancia es mas corta a la altura que queremos, vaciamos
    else
        return Vaciar; // la altura del agua llego al nivel que queremos
}

