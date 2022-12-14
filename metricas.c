# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

# define NUM_ARRAYS 8

float * array_c1;
float * array_c2;
float * array_c3;
float * array_c4;
float * array_c5;
float * array_c6;
float * array_c7;
float * array_c8;

// función para usar con qsort
float cmpfunc (const void * a, const void * b)
{
   return ( *(float*)a - *(float*)b );
}

/*
Función que lee linea a linea y carga en los arreglos c1...c8, que representan a las columnas del archivo.
 */

void loadFile(char* inputdatafile, int lines)
{    
    FILE * file = fopen(inputdatafile, "r");
    char dstLine[100];
    int len = 100;
    int counter = 0;
    char* delim = ",";
    float c1, c2, c3, c4, c5, c6, c7, c8;
    char * token;
    char * aux;

    if (!file)
    {
        printf("error al abrir archivo.\n");
    }
    else
    {
        while (!feof(file) && counter <= lines)
        {
            counter++;

            fgets(dstLine, len, file);
            
            token = strtok(dstLine, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c1 = atof(aux);
            array_c1[counter] = c1;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c2 = atof(aux);
            array_c2[counter] = c2;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c3 = atof(aux);
            array_c3[counter] = c3;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c4 = atof(aux);
            array_c4[counter] = c4;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c5 = atof(aux);
            array_c5[counter] = c5;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c6 = atof(aux);
            array_c6[counter] = c6;

            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c7 = atof(aux);
            array_c7[counter] = c7;
            
            token = strtok(NULL, delim);
            aux = (char*) malloc (strlen(token)*sizeof(char));
            strcpy(aux, token);
            c8 = atof(aux);
            array_c8[counter] = c8;

        }
    }    
    fclose(file);
}

/* 
    Función para calcular la moda de una lista dada
 */

float mode(float data[], int len) 
{
   float maxValue = 0, maxCount = 0;
   int i, j;

   for (i = 1; i <= len; i++) 
   {
      int count = 0;

      for (j = 1; j <= len; j++) 
      {
         if (data[j] == data[i])
            count++;
      }
      
      if (count > maxCount) 
      {
         maxCount = count;
         maxValue = data[i];
      }
   }

   return maxValue;
}

/* 
    Función que calcula la media, recibe un arreglo con los datos y la cantidad registros a procesar 
*/

float mean(float data[], int len)
{
    int i;
    float sum = 0.0;

    for ( i = 1; i < len; i++)
    {
        sum += data[i];
    }
    
    return sum/len;
}

/* 
    Función que ordena de menor a mayor un arreglo dado 
*/

void order_array(float data[], int len)
{
    qsort(data,len,sizeof(float), cmpfunc);
}

/* 
    Función que calcula la desviación estándar dado un arreglo y la cantidad de registros a procesar
    retorna la desviación estándar como número flotante 
*/

float standard_deviation(float data[], int len) 
{
    float sum = 0.0, mean, SD = 0.0;
    int i;

    for (i = 1; i < len; i++) 
    {
        sum += data[i];
    }
    mean = sum / len;
    for (i = 1; i < len; i++) 
    {
        SD += pow(data[i] - mean, 2);
    }

    return sqrt(SD / len);
}

/* 
función que se encarga de escribir los diferentes archivos parciales
los cuales son enviados a través de la variable filename
la variable data tiene los datos que serán escritos en el archivo
 */

void write_file(char * filename, char * data)
{
    FILE * file = fopen(filename, "a");
    fputs(data, file);
    fclose(file);
}

/* 
    Función coordinadora de metricas, 
    recibe el archivo csv y la cantidad de líneas que serán procesadas.
 */

void metricas(char * inputdatafile,  int len)
{
    
    int iter;
    char buffer[20];
    float partial_result;

    float * data_arrays[NUM_ARRAYS] = 
    {    
        array_c1 = (float*)malloc(sizeof(float)*len),
        array_c2 = (float*)malloc(sizeof(float)*len),
        array_c3 = (float*)malloc(sizeof(float)*len),
        array_c4 = (float*)malloc(sizeof(float)*len),
        array_c5 = (float*)malloc(sizeof(float)*len),
        array_c6 = (float*)malloc(sizeof(float)*len),
        array_c7 = (float*)malloc(sizeof(float)*len),
        array_c8 = (float*)malloc(sizeof(float)*len)
    };
    
    loadFile(inputdatafile, len);

    // MEDIA
    for ( iter = 0; iter < NUM_ARRAYS; iter++)
    {
        partial_result = mean(data_arrays[iter], len);
        sprintf(buffer, "%.1f\n", partial_result);
        write_file("rp_files/rp_mean.txt", buffer);
    }

    // MODA
    for ( iter = 0; iter < NUM_ARRAYS; iter++)
    {
        partial_result = mode(data_arrays[iter], len);
        sprintf(buffer, "%.1f\n", partial_result);
        write_file("rp_files/rp_mode.txt", buffer);
    }


    // DESVIACION ESTANDAR
    for ( iter = 0; iter < NUM_ARRAYS; iter++)
    {
        partial_result = standard_deviation(data_arrays[iter], len);
        sprintf(buffer, "%.1f\n", partial_result);
        write_file("rp_files/rp_sd.txt", buffer);
    }
    
    // MAXIMOS
    for ( iter = 0; iter < NUM_ARRAYS; iter++)
    {
        order_array(data_arrays[iter], len);
        partial_result = data_arrays[iter][len];
        sprintf(buffer, "%.1f\n", partial_result);
        write_file("rp_files/rp_max.txt", buffer);
    }

    // MINIMOS
    for ( iter = 0; iter < NUM_ARRAYS; iter++)
    {
        partial_result = data_arrays[iter][0];
        sprintf(buffer, "%.1f\n", partial_result);
        write_file("rp_files/rp_min.txt", buffer);
    }

}