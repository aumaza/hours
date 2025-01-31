#ifndef HOURS_H_INCLUDED
#define HOURS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60
#define MASCARA_ARCHIVO "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
#define BUFFER buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]
#define HEADER "date,hora_desde,min_desde,seq_desde,hora_hasta,min_hasta,seq_hasta\n"
#define MASC "%s,%d,%d,%d,%d,%d,%d\n"



typedef struct{

    char date[11];
    int hour_from;
    int min_from;
    int seq_from;
    int hour_to;
    int min_to;
    int seq_to;
    int final_hour;
    int final_min;
    int final_seq;

}Hour;

#endif // HOURS_H_INCLUDED

// constructor
Hour* newHour();

// funciones
void calcHours(ArrayList* lista);
void dataParser(char* path, ArrayList* lista);
void saveData(char* path, ArrayList* lista);
void showOneData(Hour* oneHour);
void showData(ArrayList* list);
int validNULL(void* string);
int optionValid();
void getData(ArrayList* lista);
void removeNewLine(char* string);
