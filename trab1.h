#ifndef __TRAB1_
#define __TRAB1_

#include <stdlib.h>
#include <stdio.h>

typedef struct dados
{
    int n;
    int* dn;
    int* yn;
    int v_ini;
    int v_min;
    int v_max;
    float k;    //coeficiente ;
    float cap_h; //capacidade maxima da termo;
    int tmax;
    float ca;
    float ct;
}dados;

typedef struct energia
{
    int termo;
    int hidri;
}energia;

dados* readInput();
dados* inic_dados(int n);
void free_dados(dados* dt, energia* e);
void print_dados(dados* d, energia* e);

#endif
