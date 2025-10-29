#ifndef MUSICA_H
#define MUSICA_H

typedef struct Musica
{

   char titulo[50];
   char autor[100];
   int ano;
   struct Musica *anterior;
   struct Musica *proximo;

} Musica;

typedef struct{ 

   int n ;// Numero de musica
   char nome [100];// Nome da playlist 
   Musica * inicio;//Ponteiro para o primeira musica 
   Musica * fim ;// ponteriro para a ultima musica 
}Play;


Musica *criarMusica(char *titulo, char *autor, int ano);
Play *criarPlay (char* nome );
void ExbirIncio(Play*p);

#endif