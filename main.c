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
    printf("Ejemplo:\n ./lab1 -i custom_1988_2020.csv -c 10000 -d\n");
    exit(2);
}

int main(int argc, char **argv)
{
    
    int option;
    int dflag = 0;
    int lines;
    char * inputdatafile;

    while((option = getopt(argc, argv, "i:c:d"))!= -1){
        switch (option) {
            case 'd':
                dflag = 1;
                break;
            
            case 'i':
                inputdatafile = optarg;
                break;

            case 'c':
                lines = atoi(optarg);
                break;

            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }

    metricas(inputdatafile, lines);

    return 0;
}
