# Lab1-Secuencial

## Instrucciones para la compilación

* make clean
* make

## Ejecucición del programa

```
 ./lab1 -i \<nombre archivo csv\> -c \<cantidad de columnas\> -d
```

Donde:

-i: nombre de archivo de entrada.

-c: cantidad de lineas de archivo de entrada.

-d: bandera o flag que permite indicar si se quiere ver por consola el resultado final de las metricas.

Ejemplo:

```
 ./lab1 -i custom_1988_2020.csv -c 10000 -d 
 ```

 Observación: Si el archivo csv no se encuentra en la misma carpeta o directorio del ejecutable, se debe indicar la ruta hacia el. 
