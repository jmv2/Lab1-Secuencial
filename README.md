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

## Salida

```
./lab1 -i custom_1988_2020.csv -c 10000 -d

Resultados finales:
Medias: 198770.6 1.0 103.4 302.7 661775744.0 7738.5 49350.2 14802.7 
Desviaciones estandar: 30.4 0.0 0.8 162.9 233736816.0 128803.5 814669.9 54410.4 
Modas: 198801.0 1.0 103.0 200.0 854211904.0 0.0 0.0 300.0 
Valores maximos: 198801.0 1.0 105.0 300.0 400260000.0 0.0 2835.0 532.0 
Valores minimos: 198801.0 1.0 103.0 100.0 390209984.0 0.0 1000.0 479.0
 ```
