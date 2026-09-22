#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Criado um ponteiro do tipo Lista na main e passado para as funções

typedef struct lista{
int valores[MAX];
int tamanho;
} Lista;

Lista* criaLista(){
Lista* s;
s = malloc(sizeof(Lista));
if(s==NULL){
return NULL;
}
s->tamanho=0;
return s;
}

void destroiLista(Lista *l){
free(l);
}

int conta(Lista* l){
return l->tamanho;
}

int vazia(Lista *l){
return l->tamanho==0;
}

int cheia(Lista *l){

return l->tamanho==MAX;

}

void imprime(Lista *l){
if(vazia(l)){
return;
}
for(int i=0; i<l->tamanho; i++){
printf("%d\n", l->valores[i]);
}
}

int insereFinal(Lista* l, int valor){
if(cheia(l)){
return 0;
}
l->valores[l->tamanho]= valor;
l->tamanho++;
return 1;
}

int inserePos(Lista *l, int valor, int pos){
if(cheia(l)){
return 0;
}

if(vazia(l)){
return insereFinal(l, valor);
}

if(pos>l->tamanho || pos<0){
return 0;
}

for(int i=l->tamanho; i>pos; i--){
l->valores[i]=l->valores[i-1];
}
l->tamanho++;
l->valores[pos]=valor;
return 1;
}

int removePos(Lista *l, int pos){
if(vazia(l) || pos<0 || pos>=l->tamanho){
return 0;
}

if(pos!=l->tamanho-1){
for(int i=pos; i<l->tamanho-1; i++){
l->valores[i]=l->valores[i+1];
}
}

l->tamanho--;
return 1;

}

int removeValor(Lista *l, int valor){


}

int buscaPos(Lista *l, int pos){

}

int buscaValor(Lista *l, int valor){
if(vazia(l)){
return -1;
}

for(int i=0; i<=l->tamanho-1; i++){
if(l->valores[i]==valor){
return i;
}
}
return -1;
}