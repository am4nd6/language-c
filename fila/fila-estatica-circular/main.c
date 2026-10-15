#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

/*
Em filas estáticas circulares, temos: um vetor com tamanho pré-definido. Temos uma variável do tipo
inteiro para identificar o inicio, um para o fim e um para identificar quantos elementos tem
na fila.
*/

typedef struct fila{
    int valores[MAX];
    int inicio;
    int fim;   
    int n;
} Fila;

/*
Função para verificar se a fila existe.
*/

bool filaEhValida(Fila *f){
    if(f==NULL) return false;
    return true;
}

/*
Função para criar a fila. Aloca um espaco para o tipo Fila, inicializa os campos inicia, 
fim e n para 0. Caso a alocacao falhe retorna NULL.
*/

Fila* criaFila(){
    Fila *f = malloc(sizeof(Fila));
    if(!filaEhValida(f)){
        return NULL;
    }

    f->n=0;
    f->inicio=0;
    f->fim=0;
    return f;
}

/*
Função para verificar se a fila está vazia. Retorna 1 se a fila estiver vazia, 0 caso contrário.
*/

int filaVazia(Fila *f){
    if(!filaEhValida(f) || f->n==0){
        return 1;
    }

    return 0;
}

/*
Função para verificar se a fila está cheia. Retorna 1 se a fila estiver cheia, 0 caso contrário.
*/

int filaCheia(Fila *f){
    if(!filaEhValida(f) || f->n==MAX){
        return 1;
    }

    return 0;
}

/*
Função para retornar o tamanho da fila. Retorna o tamanho da fila, 0 caso contrário.
*/

int tamanho(Fila *f){
    if(filaVazia(f)) return 0;
    return f->n;
}

/*
Função para retornar o elemento da frente da fila. Retorna o elemento da frente da fila, -1 caso contrário.
*/

int frente(Fila * f){
    if(filaVazia(f)){
        return -1;
    }
    return f->valores[f->inicio];
}