# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define NUMBER_OF_STRING 5
# define MAX_STRING_SIZE 40
# define COLUMN_NUMBER 8
# define FINAL_FILE "rc_metricas.txt"

void print_results(){
    FILE * finalFile = fopen(FINAL_FILE, "r");
    char line[MAX_STRING_SIZE];

    while (!feof(finalFile))
    {
         fgets(line, MAX_STRING_SIZE, finalFile);
         printf("%s", line);
    }
    

    fclose(finalFile);
}

void update_file(char * inputFile, char * titleText) {

    FILE * readFile = fopen(inputFile, "r");
    FILE * writeFile = fopen(FINAL_FILE, "a");
    char dstLine[MAX_STRING_SIZE];

    fputs(titleText, writeFile);

    for (int iter = 0; iter < COLUMN_NUMBER; iter++){
        fgets(dstLine, MAX_STRING_SIZE, readFile);
        dstLine[strcspn(dstLine, "\r\n")] = 0;
        strcat(dstLine, " ");
        fputs(dstLine, writeFile);
    }

    fclose(readFile);
    fclose(writeFile);

}

void coordinador(){

    char fileNames[NUMBER_OF_STRING][MAX_STRING_SIZE] = {
        "rp_files/rp_mean.txt",
        "rp_files/rp_sd.txt",
        "rp_files/rp_mode.txt",
        "rp_files/rp_max.txt",
        "rp_files/rp_min.txt"
    };

    for (int iter = 0; iter < NUMBER_OF_STRING; iter++){

        if(iter == 0)
            update_file(fileNames[iter], "Resultados finales:\nMedias: ");
        
        if(iter == 1)
            update_file(fileNames[iter], "\nDesviaciones estandar: ");
        
        if (iter == 2)
            update_file(fileNames[iter], "\nModas: ");
        
        if (iter == 3)
            update_file(fileNames[iter], "\nValores maximos: ");
        
        if (iter == 4)
            update_file(fileNames[iter], "\nValores minimos: ");

    }
}
