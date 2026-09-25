#include <stdlib.h>
#include <stdio.h>
// Pilha criada na main e passada para as funções

#define MAX 100 // Constante global

/* Pilha possui um vetor de valores e uma variável que sempre aponta para o que está no topo (último)
ela segue o principio de LIFO (Last In First Out) -> Último a entrar é o primeiro a sair.
Topo = -1.
*/ 

typedef struct pilha{
int valores[MAX];
int topo;
} Pilha;

/* Cria uma pilha passando o endereço de memória que está na main
e iniciamos o topo como -1 ( pois não tem ninguém)
*/

void iniciaPilha(Pilha *p){
p->topo=-1;
}

/* Se o topo é igual a -1 então a pilha está vazia, caso contrário está cheia
*/

int pilhaVazia(Pilha *p){
return p->topo==-1;
}

/* Se o topo é igual ao tamanho-1 (começa pelo 0 o vetor) 
então a pilha está cheia, caso contrário está vazia
*/

int pilhaCheia(Pilha *p){
return p->topo==MAX-1;
}

/* Inicia a pilha adicionando um valor, verifica se tá cheia, se não
incremente ao topo +1 e add ao vetor o valor x*/

void empilhar(Pilha *p, int x){

if(pilhaCheia(p)){
return;
}
p->topo++;
p->valores[p->topo]=x;
}

/* Tira o valor do topo, verifica se tá vazia, se não guarda o valor em outra variável,
decrementa o topo e retorna o valor que foi removido*/

int desempilhar(Pilha *p){
int x;
if(pilhaVazia(p)){
return 0;
}
x=p->valores[p->topo];
p->topo--;
return x;
}

/* Retorna o valor do topo sem remover, só retorna. Para isso, verifica se tá vazia primeiro.
*/

int topo(Pilha *p){

if(pilhaVazia(p)){
return 0;
}
return p->valores[p->topo];
}

/* Funções para testar a pilha */

int main(){
Pilha p;

iniciaPilha(&p);
empilhar(&p, 10);
empilhar(&p, 20);
empilhar(&p, 30);
printf("%d", topo(&p));

}

/* Funções de uma pilha:
- Inicia a pilha
- Verifica se está vazia
- Verifica se está cheia
- Empilha
- Desempilha
- Retorna o topo
*/