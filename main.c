#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "lib_hour.h"
#include "ArrayList.h"

int main(){

    ArrayList* list = al_newArrayList();
    validNULL(list);
    //Hour* oneHour = newHour();
    dataParser("data.csv", list);


    system("clear");

    int opcion;

            do
            {

                printf("\n======================================");
                printf("\nSeleccione la Operacion a Realizar");
                printf("\n======================================\n");
                printf("\n1. Listar Data Cargada");
                printf("\n2. Cargar Data");
                printf("\n3. Calcular Horas Trabajadas");
                printf("\n4. Guardar Data");
                printf("\n\n======================================\n");
                printf("\n0. Salir");

                opcion = optionValid();
                printf("\n======================================\n");

                switch(opcion){

                    case 1: showData(list); break;
                    case 2: getData(list); break;
                    case 3: calcHours(list); break;
                    case 4: saveData("data.csv", list); break;
                    case 5: break;
                    case 6: break;
                    case 7: break;
                }
            }
            while(opcion != 0);


    /*
    printf("Calulo de Horas Trabajadas");
    printf("\nIngrese la hora de entrada: ");
    scanf("%d", &nHour->hour);
    printf("Ingrese los minutos: ");
    scanf("%d", &nHour->min);
    printf("Ingrese los segundos: ");
    scanf("%d", &nHour->seq);

    system("clear");

    printf("\nIngrese la hora de salida: ");
    scanf("%d", &mHour->hour);
    printf("Ingrese los minutos: ");
    scanf("%d", &mHour->min);
    printf("Ingrese los segundos: ");
    scanf("%d", &mHour->seq);

    system("clear");
    */

    //calcHours ( nHour, mHour );

    return 0;
}
