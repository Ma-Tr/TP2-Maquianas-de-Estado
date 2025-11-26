#include "config.h"
Estados_t f_Espera(nivel_t nivel) {

    LLENADO = 0; //seteamos la salida de llenado a 0
    VACIADO = 0; // seteamos la salida de VACIADO a 0

    nivel.N = medir_distancia_cm(); //medimos la distancia que hay del sensor al nivel del agua

    if (nivel.N > nivel.Set_N + nivel.Delta_N)
        return LLENAR; // como la distancia es mucha a la altura que queremos, llenamos
	
    else if (nivel.N < nivel.Set_N - nivel.Delta_N)
        return VACIAR; // como la distancia es mas corta a la altura que queremos, vaciamos
	
    else
        return ESPERA;
}

Estados_t f_Llenar(nivel_t nivel) {
    LLENADO = 1;
    VACIADO = 0;

    nivel.N = medir_distancia_cm();

    if (nivel.N < nivel.Set_N)
        return ESPERA; // como la distancia es mucha a la altura que queremos, llenamos
    else
        return LLENAR; // la altura del agua llego al nivel que queremos
}

Estados_t f_Vaciar(nivel_t nivel) {
    LLENADO = 0;
    VACIADO = 1;

    nivel.N = medir_distancia_cm();

    if (nivel.N > nivel.Set_N)
        return ESPERA; // como la distancia es mas corta a la altura que queremos, vaciamos
    else
        return VACIAR; // la altura del agua llego al nivel que queremos
}



