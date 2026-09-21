#include <stdlib.h>
// Pilha criada na main e passada para as funções

#define MAX 100

typedef struct pilha{
int valores[MAX];
int topo;
} Pilha;

void iniciaPilha(Pilha *p){
p->topo=-1;
}

int pilhaVazia(Pilha *p){
return p->topo==-1;
}

int pilhaCheia(Pilha *p){
return p->topo==MAX-1;
}

void empilhar(Pilha *p, int x){

if(pilhaCheia(p)){
return;
}
p->topo++;
p->valores[p->topo]=x;
}


int desempilhar(Pilha *p){
int x;
if(pilhaVazia(p)){
return 0;
}
x=p->valores[p->topo];
p->topo--;
return x;
}

int topo(Pilha *p){

if(pilhaVazia(p)){
return 0;
}
return p->valores[p->topo];
}

int main(){
Pilha p;

iniciaPilha(&p);
empilhar(&p, 10);
empilhar(&p, 20);
empilhar(&p, 30);
printf("%d", topo(&p));

}
