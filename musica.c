#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"
Musica *criarMusica(char *titulo, char *autor, int ano)
{

    Musica *x = (Musica *)malloc(sizeof(Musica));
    if (x == NULL)
    {
        printf("ERRO: não foi possivel alocar memoria para um item (musicar)");
        return NULL;
    }

    strcpy(x->titulo, titulo);
    x->ano = ano;
    x->proximo = NULL;
    x->anterior = NULL;

    return x;
}
Play *criarPlay(char *nome)
{

    Play *p = (Play *)malloc(sizeof(Play));

    if (p == NULL)
    {
        printf("ERRO: não foi possivel alocar memoria para um item (play)");
        return NULL;
    }

    p->n = 0;
    strcpy(p->nome, nome);

    p->inicio = NULL;
    p->fim = NULL;
}

void ExbirIncio(Play *p)
{
    Musica *atual = p->inicio;
    for (int i = 1; atual != NULL; i++)
    {
        printf("%d\t%s\n", i, atual->titulo);
        atual = atual->proximo;
    }
}

void ExbirFinal(Play *p)
{
    Musica *atual = p->fim;
    for (int i = 5; atual != NULL; i++)
    {
        printf("%d\t%s\n", i, atual->titulo);
        atual = atual->anterior;
    }
}