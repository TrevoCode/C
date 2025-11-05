#ifndef FILA_H
#define FILAS_H

//definido o item de uma lista encadeada

typedef struct
{
    int chave;
    struct item *proximo;

} item;
//definido a estrutura da lista (filas) propriamento dita 

typedef struct filas
{
    int tamanho ;
    item * inicio;
    item * fim;
    
}filas;

item *criarItem(int chave);
filas * criaFila();
void enfileira(filas * f, item * i);
void desfileriar (filas *f );
int verificar( filas * chave );//verificar se o item (chaver)
#endif
