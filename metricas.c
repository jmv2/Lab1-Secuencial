# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

float * array_c1;
float * array_c2;
float * array_c3;
float * array_c4;
float * array_c5;
float * array_c6;
float * array_c7;
float * array_c8;

// función para usar con qsort
float cmpfunc (const void * a, const void * b) {
   return ( *(float*)a - *(float*)b );
}

void loadFile(char* inputdatafile, int lines){
    
    
    FILE * file = fopen(inputdatafile, "r");
    char dstLine[100];
    int len = 100;
    int contador = 0;
    char* delim = ",";
    float c1, c2, c3, c4, c5, c6, c7, c8;
    char * token;
    char * aux;

    if (!file){
        printf("error al abrir archivo.\n");
    }else{
        while (!feof(file) && contador <= lines){
            contador++;

            fgets(dstLine, len, file);
            
            token = strtok(dstLine, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c1 = atof(aux);
            array_c1[contador] = c1;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c2 = atof(aux);
            array_c2[contador] = c2;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c3 = atof(aux);
            array_c3[contador] = c3;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c4 = atof(aux);
            array_c4[contador] = c4;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c5 = atof(aux);
            array_c5[contador] = c5;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c6 = atof(aux);
            array_c6[contador] = c6;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c7 = atof(aux);
            array_c7[contador] = c7;
            
            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c8 = atof(aux);
            array_c8[contador] = c8;

        }
    }    
    fclose(file);
}

//Función para calcular la moda de una lista dada

float mode(float data[], int len) {
   float maxValue = 0, maxCount = 0;
   int i, j;

   for (i = 1; i <= len; i++) {
      int count = 0;

      for (j = 1; j <= len; j++) {
         if (data[j] == data[i])
            count++;
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = data[i];
      }
   }

   return maxValue;
}

float mean(float data[], int len){
    int i;
    float sum = 0.0;

    for ( i = 1; i < len; i++)
    {
        sum += data[i];
    }
    
    return sum/len;
}

void order_array(float data[], int len){
    qsort(data,len,sizeof(float), cmpfunc);

}

float standard_deviation(float data[], int len) {
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 1; i < len; i++) {
        sum += data[i];
    }
    mean = sum / len;
    for (i = 1; i < len; i++) {
        SD += pow(data[i] - mean, 2);
    }
    return sqrt(SD / len);
}


void metricas(char * inputdatafile,  int len){

    array_c1 = (float*)malloc(sizeof(float)*len);
    array_c2 = (float*)malloc(sizeof(float)*len);
    array_c3 = (float*)malloc(sizeof(float)*len);
    array_c4 = (float*)malloc(sizeof(float)*len);
    array_c5 = (float*)malloc(sizeof(float)*len);
    array_c6 = (float*)malloc(sizeof(float)*len);
    array_c7 = (float*)malloc(sizeof(float)*len);
    array_c8 = (float*)malloc(sizeof(float)*len);

    
    loadFile(inputdatafile, len);

    printf("moda columna 5: %.1f\n",mode(array_c5, len));
    printf("moda columna 7: %.1f\n",mode(array_c7, len));
    printf("Media columna 5: %.1f\n", mean(array_c5, len));
    printf("Media columna 7: %.1f\n", mean(array_c7, len));

    order_array(array_c7, len);
    printf("valor min col 7: %.0f\n", array_c7[0]);
    printf("valor max col 7: %.0f\n", array_c7[len]);

    printf("Desviacion estandar para col 7: %.1f\n", standard_deviation(array_c7,len));
    
}