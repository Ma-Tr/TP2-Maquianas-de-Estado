# LLENADO DE TANQUE DE AGUA

El sistema tiene como objetivo regular automáticamente el nivel de agua en un tanque, manteniéndolo dentro de un Delta deseado mediante el uso de un sensor ultrasónico y un conjunto de accionadores que controlan la entrada y salida de agua.

![./RECURSOS/Diagrama de Estado (ver2).png](https://github.com/Ma-Tr/TP2-Maquianas-de-Estado/blob/main/RECURSOS/Diagrama%20de%20Estado%20(ver2).png)

## ESPERA – Inicio del sistema. 
Este es el estado inicial en el que ingresa el sistema al ser encendido.
En esta etapa se realizan las configuraciones necesarias, tales como inicialización del sensor ultrasónico, ajuste de valores de referencia y verificación del correcto funcionamiento de los dispositivos de entrada y salida.
Una vez completada la inicialización, el sistema pasa automáticamente al estado de monitoreo.

## ESPERA – Nivel dentro del rango deseado (Estado 1).
En este estado el sistema detecta que el nivel de agua se encuentra dentro de los límites establecidos como seguros y aceptables.
No se realizan acciones de llenado ni de vaciado. El sistema continúa midiendo el nivel de forma periódica para cambiar de estado en caso que sea necesario.

## LLENADO – Nivel por debajo del margen inferior (Estado 2).
Cuando el sensor indica que el nivel de agua está por debajo del límite inferior permitido, el sistema pasa a este estado.
Aquí se activan las compuertas de llenado, permitiendo la entrada de agua al tanque.
El estado se mantiene hasta que el nivel vuelva a entrar dentro del rango deseado, momento en el que el sistema regresa al Estado 1.

## VACIADO – Nivel por encima del margen superior (Estado 3).
Si el nivel de agua supera el límite superior preestablecido, el sistema ingresa a este estado.
En este estado se habilitan las compuertas de vaciado, permitiendo la salida de agua para reducir el nivel.
Una vez que el nivel retorna al rango deseado, el sistema vuelve al Estado 1.


# CARPETA PROYECTO

En esta carpeta se encuentra una versión temprana del código.
En esta etapa inicial se utilizaron entradas y salidas con nombres genéricos (Entradas: E1, E2, E3; Salidas: S1, S2, S3), únicamente para verificar el funcionamiento básico y el progreso del desarrollo.

Esta versión del programa es funcional, pero no cuenta con funciones separadas por estado dentro de la máquina de estados.

# CARPETA PROYECTO v1.1

Esta carpeta contiene la versión más reciente del código.
Incluye la implementación completa de funciones dedicadas para cada estado de la máquina de estados, lo que mejora la organización y la mantenibilidad del proyecto.

Además, incorpora la librería personalizada MYLIB.h, donde se centralizan los prototipos y definiciones del sistema.

![./RECURSOS/Proyecto en proteus.png](https://github.com/Ma-Tr/TP2-Maquianas-de-Estado/blob/main/RECURSOS/Proyecto%20en%20proteus.png)
