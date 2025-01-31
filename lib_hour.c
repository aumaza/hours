// <one line to give the program's name and a brief idea of what it does.>
// SPDX-FileCopyrightText: 2024 Augusto Maza <email>
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "lib_hour.h"


void removeNewLine(char* string){
  size_t length;

  if((length = strlen(string)) > 0){
       if(string[length-1] == '\n'){
                string[length-1] = '\0';
       }
  }
}

void saveData(char* path, ArrayList* lista){

    FILE* fp;
    fp = fopen(path,"w");
    Hour* nHour;

    if(fp != NULL){

        fprintf(fp,HEADER);

        for(int i=0; i<lista->len(lista); i++){

            nHour = (Hour*)lista->get(lista,i);
            fprintf(fp,MASC,nHour->date,nHour->hour_from,nHour->min_from,nHour->seq_from,nHour->hour_to,nHour->min_to,nHour->seq_to);

        }

        fclose(fp);
    }
}


int optionValid(){

   int ok;
   int ch;
   int opc;

    do{

      printf("\nOpcion: ");
      fflush(stdout);
      if ((ok = scanf("%d", &opc)) == EOF)
         return 1;


      if ((ch = getchar()) != '\n'){

          ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);

   return opc;
}

int validNULL(void* string){

    if(string == NULL){
        return 1;
    }else{
        printf("SUCCESS!!\n");
        return 0;
    }
}

// constructor
Hour * newHour(){
    Hour* nHour = (Hour*)malloc(sizeof(Hour));

    if(nHour != NULL){

        strcpy(nHour->date,"");
        nHour->hour_from = 0;
        nHour->min_from = 0;
        nHour->seq_from = 0;
        nHour->hour_to = 0;
        nHour->min_to = 0;
        nHour->seq_to = 0;
        nHour->final_hour = 0;
        nHour->final_min = 0;
        nHour->final_seq = 0;

    }

    return nHour;
}

void dataParser(char* path, ArrayList* lista)
{
    FILE* fp;

    Hour* nHour;

    int cant;
    char buffer[7][128];
    fp=fopen(path, "a+");

    if(fp != NULL && lista != NULL)
    {
        fscanf(fp,MASCARA_ARCHIVO,BUFFER);

        while(!feof(fp))
        {
            cant = fscanf(fp,MASCARA_ARCHIVO,BUFFER);

            if( cant == 7)
            {
                nHour = newHour();

                if(nHour != NULL)
                {
                    strcpy(nHour->date,buffer[0]);
                    nHour->hour_from = atoi(buffer[1]);
                    nHour->min_from = atoi(buffer[2]);
                    nHour->seq_from = atoi(buffer[3]);
                    nHour->hour_to = atoi(buffer[4]);
                    nHour->min_to = atoi(buffer[5]);
                    nHour->seq_to = atoi(buffer[6]);

                    lista->add(lista,nHour);
                }
            }
            else
            {
                break;
            }
        }
        fclose(fp);
    }
}


void calcHours(ArrayList* lista){

    Hour* auxHour = newHour();
    int aux_hour_a;
    int aux_min_a;
    int aux_sec_a;
    int aux_hour_b;
    int aux_min_b;
    int aux_sec_b;
    int final_hour;
    int final_min;

    if(auxHour != NULL){

        for(int i = 0; i < lista->len(lista); i++){

            auxHour = (Hour*)lista->get(lista, i);
            // se pasan las horas y min a segundos sobre la hora inicial
            aux_hour_a = auxHour->hour_from * SEC_PER_HOUR;
            aux_min_a = auxHour->min_from * SEC_PER_MIN;
            aux_sec_a = aux_hour_a + aux_min_a;


            // se pasan las horas y min a segundos sobre la hora final
            aux_hour_b = auxHour->hour_to * SEC_PER_HOUR;
            aux_min_b = auxHour->min_to * SEC_PER_MIN;
            aux_sec_b = aux_hour_b + aux_min_b;

            // se calcula la diferencia de horas
            // la formula es (((H2 + Min2) - (H1 + Min1)) - (3600 - (Min1 + Min2))) / 360
            final_hour = (((aux_hour_b + aux_min_b) - (aux_hour_a + aux_min_a) - (SEC_PER_HOUR - (aux_min_a + aux_min_b)))) / SEC_PER_HOUR;
            // se calculan los minutos
            // la formula es (3600 - (Min1 + Min2)) / 60
            final_min = (SEC_PER_HOUR - (aux_min_a + aux_min_b)) / SEC_PER_MIN;

            system("clear");
            printf("Hora: %d\n", auxHour->final_hour = final_hour);
            printf("Minutos: %d\n", auxHour->final_min = final_min);
            printf("Segundos: %d\n", auxHour->final_seq = aux_sec_b - aux_sec_a);

        }

    }

        getchar();
        system("clear");

}


void getData(ArrayList* lista){

    Hour* nHour;

    if(lista != NULL){

        nHour = newHour();

        if(nHour != NULL){

            system("clear");

            printf("Ingrese la Fecha: ");
            fflush(stdin);
            fgets(nHour->date,11,stdin);
            removeNewLine(nHour->date);
            getchar();


            printf("Ingrese la hora de entrada: ");
            fflush(stdin);
            scanf("%d", &nHour->hour_from);

            printf("Ingrese los minutos: ");
            fflush(stdin);
            scanf("%d", &nHour->min_from);

            printf("Ingrese los segundos: ");
            fflush(stdin);
            scanf("%d", &nHour->seq_from);

            system("clear");

            printf("Ingrese la hora de salida: ");
            fflush(stdin);
            scanf("%d", &nHour->hour_to);

            printf("Ingrese los minutos: ");
            fflush(stdin);
            scanf("%d", &nHour->min_to);

            printf("Ingrese los segundos: ");
            fflush(stdin);
            scanf("%d", &nHour->seq_to);

            lista->add(lista,nHour);
        }

    }

}

void showOneData(Hour* oneHour){

    printf("%s", oneHour->date);
    printf("\t%4d:%d:%d", oneHour->hour_from, oneHour->min_from, oneHour->seq_from);
    printf("\t%12d:%d:%d\n", oneHour->hour_to, oneHour->min_to, oneHour->seq_to);

}

void showData(ArrayList* lista){

    system("clear");
    Hour* oneHour;
    printf("\n========================================================================================");
    printf("\n------------------------------------ HORAS CARGADAS ------------------------------------");
    printf("\n========================================================================================");
    printf("\nFecha    \tHora Entrada    \tHora Salida");
    printf("\n========================================================================================\n");

    for(int i = 0; i < lista->len(lista); i++){

        oneHour = (Hour*)lista->get(lista,i);
        showOneData(oneHour);
    }

    printf("\n========================================================================================\n");
    getchar();
    system("clear");


}

