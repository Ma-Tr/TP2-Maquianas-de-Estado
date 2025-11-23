#include "config.h"
Estados_t f_Espera(Nivel_t nivel) {

    Llenado = 0; //seteamos la salida de llenado a 0
    Vaciado = 0; // seteamos la salida de vaciado a 0

    nivel.N = medir_distancia_cm(); //medimos la distancia que hay del sensor al nivel del agua

    if (nivel.N > nivel.Set_N + nivel.Delta_N)
        return Llenar; // como la distancia es mucha a la altura que queremos, llenamos
	
    else if (nivel.N < nivel.Set_N - nivel.Delta_N)
        return Vaciar; // como la distancia es mas corta a la altura que queremos, vaciamos
	
    else
        return Espera;
}
