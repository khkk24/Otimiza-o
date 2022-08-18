// GRR2017300-khkk17 

#include "trab1.h"

int main()
{
    energia* e = malloc(sizeof(energia));
    dados* d;
    d = malloc (sizeof (dados));
    e->hidri = 0;
    e->termo = 0;

    d = readInput();
    print_dados(d,e);
    free_dados(d,e);

    return 0;

}