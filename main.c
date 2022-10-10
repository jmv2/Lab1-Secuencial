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

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char **argv)
{
    
    int option;
    int dflag = 0;
    int lines;
    char * inputfile;

    while((option = getopt(argc, argv, "i:c:d"))!= -1){
        switch (option) {
            case 'd':
                dflag = 1;
                break;
            
            case 'i':
                inputfile = optarg;
                break;

            case 'c':
                lines = atoi(optarg);
                break;

            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }
    // printf("lineas: %d\n", lines);
    // loadFile(inputfile, lines);

    int vector[10] = {1,3,45,3,6576,2,3,8,56,0};
    int i ;
    for ( i = 0; i < 10; i++)
    {
        printf("%d\n",vector[i]);
    }
    
    qsort(vector, 10, sizeof(int), cmpfunc);

    printf("*******\n");

    for ( i = 0; i < 10; i++)
    {
        printf("%d\n",vector[i]);
    }

    printf("ahora, la moda: %d", mode(vector, 10));

    return 0;
}
