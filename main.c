#include <stdio.h>
#include <stdlib.h>

#include "filas.h"

int main()
{
    item *a = criarItem(23);
    item *b = criarItem(45);
    item *c = criarItem(88);

    filas * normal= criaFila();
    filas * p= criaFila();
 
    enfileira(normal,a);
    enfileira(normal,b);
    enfileira(normal,c);

    exbirfilas (normal);

}