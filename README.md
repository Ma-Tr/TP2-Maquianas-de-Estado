# Máquinas de Estado

El sistema tiene como objetivo regular automáticamente el nivel de agua en un tanque, manteniéndolo dentro de un Delta deseado mediante el uso de un sensor ultrasónico y un conjunto de accionadores que controlan la entrada y salida de agua.

Image
Estado 0 – Inicio del sistema. Este es el estado inicial en el que ingresa el sistema al ser encendido.
En esta etapa se realizan las configuraciones necesarias, tales como inicialización del sensor ultrasónico, ajuste de valores de referencia y verificación del correcto funcionamiento de los dispositivos de entrada y salida.
Una vez completada la inicialización, el sistema pasa automáticamente al estado de monitoreo.

Estado 1 – Estado de Espera (Nivel dentro del rango deseado). En este estado el sistema detecta que el nivel de agua se encuentra dentro de los límites establecidos como seguros y aceptables.
No se realizan acciones de llenado ni de vaciado. El sistema continúa midiendo el nivel de forma periódica para cambiar de estado en caso que sea necesario.

Estado 2 – Llenado (Nivel por debajo del margen inferior). Cuando el sensor indica que el nivel de agua está por debajo del límite inferior permitido, el sistema pasa a este estado.
Aquí se activan las compuertas de llenado, permitiendo la entrada de agua al tanque.
El estado se mantiene hasta que el nivel vuelva a entrar dentro del rango deseado, momento en el que el sistema regresa al Estado 1.

Estado 3 – Vaciado (Nivel por encima del margen superior). Si el nivel de agua supera el límite superior preestablecido, el sistema ingresa a este estado.
En este estado se habilitan las compuertas de vaciado, permitiendo la salida de agua para reducir el nivel.
Una vez que el nivel retorna al rango deseado, el sistema vuelve al Estado 1.
