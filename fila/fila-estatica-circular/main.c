#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct fila{
    int valores[MAX];
    int inicio;
    int fim;   
    int n;
} Fila;

bool filaEhValida(Fila *f){
    if(f==NULL) return false;
    return true;
}

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

int filaVazia(Fila *f){
    if(!filaEhValida(f) || f->n==0){
        return 1;
    }

    return 0;
}

int filaCheia(Fila *f){
    if(!filaEhValida(f) || f->n==MAX){
        return 1;
    }

    return 0;
}

int tamanho(Fila *f){
    if(filaVazia(f)) return 0;
    return f->n;
}

int frente(Fila * f){
    if(filaVazia(f)){
        return -1;
    }
    return f->valores[f->inicio];
}