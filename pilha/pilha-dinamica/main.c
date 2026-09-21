#include <stdio.h>
#include <stdlib.h>

// Criado um ponteiro do tipo Pilha na main e passado para as funções

typedef struct pilha{

int *valores;
int topo;
int tamanho;

} Pilha;

Pilha* criaPilha(int t){
Pilha *p;
p=malloc(sizeof(Pilha));

if(p==NULL){
return NULL;
}

p->topo=-1;
p->tamanho=t;
p->valores= malloc(t* sizeof(int));
if(p->valores==NULL){
free(p);
return NULL;
}
return p;
}

int pilhaVazia(Pilha *p){
return p->topo==-1;
}

int pilhaCheia(Pilha *p){
return p->topo==p->tamanho-1;
}

void empilhar(Pilha *p, int valor){

if(pilhaCheia(p)){
return;
}
p->topo++;
p->valores[p->topo]=valor;
}

int desempilhar(Pilha *p){
if(pilhaVazia(p)){
return -1;
}

int x;
x = p->valores[p->topo];
p->topo--;

return x;
}

int main(){
Pilha *p;
p = criaPilha(5);
empilhar(p, 10);
empilhar(p, 20);
empilhar(p, 30);
printf("%d", desempilhar(p));
free(p->valores);
free(p);
return 0;
}