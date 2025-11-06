#include <stdio.h>    // Para manipulação de arquivos
#include <stdlib.h>   // Para alocação de memória (malloc, free)
#include <string.h>   // Para manipulação de strings
#include "cidades.h"  // Header obrigatório

// === Funções Auxiliares (Definidas no escopo de cidades.c) ===
// (A função 'criaNovaCidade' e 'insereCidadeOrdenada' do esqueleto anterior seriam colocadas aqui)
// ...

/**
 * @brief Libera toda a memória alocada para a estrutura Estrada e sua lista de Cidades.
 * @param est Ponteiro para a estrutura Estrada a ser liberada.
 */
void liberaEstrada(Estrada *est) {
    if (est == NULL) {
        return;
    }
    
    // Libera a lista encadeada de Cidades
    Cidade *atual = est->Inicio.Proximo;
    Cidade *proximo;
    while (atual != NULL) {
        proximo = atual->Proximo;
        free(atual);
        atual = proximo;
    }
    
    // Libera a estrutura Estrada
    free(est);
}

// =========================================================================
// IMPLEMENTAÇÃO DE getEstrada
// =========================================================================

/**
 * @brief Lê, valida restrições e inicializa uma lista encadeada de cidades (ordenada por posição).
 * Em caso de violação das restrições, retorna NULL[cite: 82].
 * @param nomeArquivo Nome do arquivo de entrada.
 * @return Ponteiro para a estrutura Estrada ou NULL.
 */
Estrada *getEstrada (const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return NULL; // Não conseguiu abrir o arquivo
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    if (estrada == NULL) {
        fclose(arquivo);
        return NULL; // Falha na alocação da Estrada
    }

    // 1. Leitura de T e N
    if (fscanf(arquivo, "%d", &estrada->T) != 1 || // Lê T (Comprimento total) [cite: 10]
        fscanf(arquivo, "%d", &estrada->N) != 1) { // Lê N (Número de cidades) [cite: 11]
        liberaEstrada(estrada);
        fclose(arquivo);
        return NULL;
    }

    // 2. Validação das Restrições de T e N [cite: 20]
    // Restrições: 3 <= T <= 10^6 e 2 <= N <= 10^4
    if (estrada->T < 3 || estrada->T > 1000000 || 
        estrada->N < 2 || estrada->N > 10000) {
        liberaEstrada(estrada);
        fclose(arquivo);
        return NULL;
    }

    // Inicialização do ponteiro de cabeça da lista (sentinela/dummy node)
    estrada->Inicio.Proximo = NULL; 

    // Estrutura auxiliar para checar a restrição: Xi != Xj [cite: 22]
    // Usamos um array de ponteiros para Cidade para simplificar a checagem
    // de duplicatas. Como N_max é 10^4, é viável.
    // Poderia ser usada uma Tabela Hash, mas um array simples resolve.
    int *posicoesLidas = (int *)calloc(estrada->N, sizeof(int));
    if (posicoesLidas == NULL) {
        liberaEstrada(estrada);
        fclose(arquivo);
        return NULL;
    }

    // 3. Leitura e Inserção das Cidades
    int i, posicao;
    char nome[256];
    int leituraSucesso = 1;

    for (i = 0; i < estrada->N; i++) {
        // Lê a posição (Xi) e o nome (Si) [cite: 12]
        if (fscanf(arquivo, "%d %s", &posicao, nome) != 2) {
            leituraSucesso = 0;
            break;
        }
        
        // 4. Validação da Posição (Xi) [cite: 21]
        // Restrição: 0 < Xi < T
        if (posicao <= 0 || posicao >= estrada->T) {
            leituraSucesso = 0;
            break;
        }

        // 5. Validação de Duplicatas (Xi != Xj) [cite: 22]
        for (int j = 0; j < i; j++) {
            if (posicoesLidas[j] == posicao) {
                // Posição duplicada encontrada
                leituraSucesso = 0;
                break;
            }
        }
        if (!leituraSucesso) break;

        // Se passar nas validações, armazena a posição e insere na lista:
        posicoesLidas[i] = posicao;
        
        Cidade *novaCidade = criaNovaCidade(posicao, nome); // Função auxiliar
        if (novaCidade == NULL) {
            leituraSucesso = 0; // Falha na alocação
            break;
        }
        
        // Insere na lista encadeada, garantindo a ORDEM por Posicao
        // (necessária para calcular a vizinhança facilmente)
        insereCidadeOrdenada(&estrada->Inicio.Proximo, novaCidade); // Função auxiliar
    }
    
    // 6. Limpeza e Retorno
    free(posicoesLidas);
    fclose(arquivo);

    if (!leituraSucesso) {
        // Se houve violação de restrição [cite: 23] ou erro de leitura/alocação
        liberaEstrada(estrada);
        return NULL;
    }

    // Retorna a estrutura Estrada alocada e montada
    return estrada;
}