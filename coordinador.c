#include <stdio.h>

void loadFile(char* filename, int lines){
    FILE * file = fopen(filename, "rb");
    char dstLine[50];
    int len = 50;
    int contador = 0;

    if (!file){
        printf("error al abrir archivo.\n");
    }else{
        printf("archivo abierto ok.\n");
    }


    while (!feof(file) && contador <= lines)
    {
        printf("%d: %s",contador, fgets(dstLine, len, file));
        contador++;
    }
    

    fclose(file);
}