#include <stdio.h>
#include <stdlib.h>

typedef struct no{
     No *valores;
     No *proximo;
} No;

typedef struct lista{
    No *inicio;
    int tamanho;
} Lista;

/* Funções de uma lista dinâmica:
- Criar a lista
- Destruir a lista
- Conta o tamanho da lista
- Verifica se a lista está vazia
- Verifica se a lista está cheia
- Imprime a lista
- Insere no final
- Insere na posição
- Remove na posição
- Remove todas as ocorrências de um valor
- Remove a primeira ocorrência de um valor
- Busca na posição
- Busca todas as ocorrências de um valor
- Busca a primeira ocorrência de um valor
*/