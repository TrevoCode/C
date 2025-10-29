#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

int main()
{

Musica * D= criarMusica("Aquarela", "Toquinho", 1983);
Musica * E= criarMusica("Romaria", "Renato Teixeira", 1978);
Musica * F= criarMusica("Eu nasci ha dez mil anos atras", "Raul Seixas", 1976);
Musica * G= criarMusica("Calise", "Chico Buarque e Gilberto Gil", 1978);
Musica * H= criarMusica ("Tempo perdido", "Renato Russo", 1986);

// comstruindo o encadeamento D,E,F,G,H

Play * minhaLista =criarPlay("MPB");


D->proximo =E;
E->anterior=D;


E->proximo=F;
F->anterior=E;

F->proximo=G;
G->anterior=F;

G->proximo =H;
H->anterior=G;

minhaLista->inicio=D;
minhaLista->fim=H;
minhaLista->n=5;


minhaLista->fim=H;
minhaLista->inicio=D;
minhaLista->n=5;

ExbirIncio(minhaLista);


Musica * i = criarMusica("e","Gonzaguinha",1990);

G->proximo= i;
i->anterior=G;

i->proximo =H;
H->anterior= i;

minhaLista->n++;

ExbirFinal(minhaLista);







 /* Musica D = {"Aquarela", "Toquinho", 1983, NULL, NULL};
  Musica E = {"Romaria", "Renato Teixeira", 1978, NULL, NULL};
  Musica F = {"Eu nasci ha dez mil anos atras", "Raul Seixas", 1976, NULL, NULL};
  Musica G = {"Calise", "Chico Buarque e Gilberto Gil", 1978, NULL, NULL};
  Musica H = {"Tempo perdido", "Renato Russo", 1986, NULL, NULL};

  D.proximo = &E;
  printf("%s", D.proximo->titulo);

*/

}