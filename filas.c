#include <stdio.h>
#include <stdlib.h>

#include "filas.h"

item *criarItem(int chave)
{

    item *x = (item *)malloc(sizeof(item));
    if (x == NULL)
    {
        printf("ERRO: nao foi possivel alocar memoria para o item");
        return NULL;
    }

    x->chave = chave;
    x->proximo = NULL;

    return x;
}
filas *criaFila()
{
    filas *f = (filas *)malloc(sizeof(filas));
    if (f == NULL)
    {
        printf("ERRO: nao foi possivel alocar memoria para a fila"); // Corrigido a mensagem
        return NULL;
    }
    // ESTAS LINHAS FORAM MOVIDAS PARA DENTRO DO ESCOPO CORRETO
    f->tamanho = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
void enfileira(filas *f, item *i)
{
    if (f == NULL || i == NULL) return; // Adicionada checagem de NULL para segurança

    if (f->tamanho == 0)
    {
        f->inicio = i;
        f->fim = i;
    }
    else // Fila não está vazia
    {
        f->fim->proximo = i; // O 'proximo' do antigo fim aponta para o novo item
        f->fim = i;          // O 'fim' da fila agora é o novo item
    }
    f->tamanho++; // O incremento de tamanho é comum a ambos os casos
}

void exibirrFilas(filas *f)
{

    item *atual = f->inicio;

    for (int i = 0; i < f->tamanho; i++)
    {

        printf("%d\t", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}
void desfileriar (filas *f ){

  if (f -> tamanho == 0){
    printf("ERRO: a filas esta vazia ");
    return;
  }
  item * atual =f ->inicio;
   f->inicio= f->inicio->proximo;
   free(atual);
   f->tamanho --;

}

int verificar(filas * f ,int chave){

    item *atual = f-> inicio;

    for (int i = 0; i< f->tamanho;i++){

        
    }
}

