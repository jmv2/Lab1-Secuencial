#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include "coordinador.h"
#include "metricas.h"

void print_usage(){
    printf("Error al ejecutar programa, faltan las opciones\n");
    printf("-i: nombre de archivo de entrada\n");
    printf("-c: cantidad de lineas de archivo de entrada.\n");
    printf("-d: bandera o flag que permite indicar si se quiere ver por consola el resultado final de las metricas.\n");
    printf("Ejemplo:\n ./program -i custom_1988_2020.csv -c 10000 -d\n");
    exit(2);
}


int main(int argc, char **argv)
{
    
    int option;
    int dflag = 0;
    int cvalue;
    char * ivalue;

    while((option = getopt(argc, argv, "i:c:d"))!= -1){
        switch (option) {
            case 'd':
                dflag = 1;
                break;
            
            case 'i':
                ivalue = optarg;
                printf("valor de i: %s\n", ivalue);
                break;
            case 'c':
                cvalue = atoi(optarg);
                printf("Cantidad de columnas: %d\n", cvalue);
                break;

            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}
