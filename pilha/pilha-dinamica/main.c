#include <stdio.h>
#include <stdlib.h>

// Criado um ponteiro do tipo Pilha na main e passado para as funções


/* Pilha dinâmica deve possuir um ponteiro para valores porque pode ser n valores em uma pilha.
Por isso, ela recebe a quantidade de valores que deseja e aloca na memória.
Depois, temos uma variável para saber quem está no topo e por último o tamanho para saber a quantidade
que tem total de valores alocados. Tamanho = 0 e Topo = -1 significa que está vazia.
Seguindo o princípio de LIFO (Last In First Out) -> Último a entrar é o primeiro a sair*/ 

typedef struct pilha{

int *valores;
int topo;
int tamanho;

} Pilha;

/* Retorna o endereço alocado do tipo pilha. 
Cria outro ponteiro do tipo pilha, faz um malloc no endereço desse ponteiro e passa para o ponteiro p
Verifica se p é nulo, se for retorna NULL, isso serve para verificar se a alocação funcionou.
Se estiver nulo, é porque não tem memória suficiente para alocar, 
então para evitar quebra de ponteiro, retorna NULL.
Inicia o topo em -1 e o tamanho em t (foi passado na função a quantidade total de valores).
Faz um malloc no endereço do vetor valores com a quantidade de valores que serão alocados
Verifica se valores é nulo, se for libera p e retorna NULL, também para evitar quebra de ponteiro.
Por último retorna p, o enderço em que iniciou a alocação do tipo pilha.
*/

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

/* Verifica se a pilha está vazia, ou seja, se o topo é igual a -1*/

int pilhaVazia(Pilha *p){
return p->topo==-1;
}

/* Verifica se a pilha está cheia, ou seja, se o topo é igual ao tamanho-1
Lembre-se que o vetor começa em 0, então tamanho total vai ser tamanho-1.*/

int pilhaCheia(Pilha *p){
return p->topo==p->tamanho-1;
}

/* Verifica se está cheia, se não estiver incrementa o topo
e adiciona o valor ao topo*/

void empilhar(Pilha *p, int valor){

if(pilhaCheia(p)){
return;
}
p->topo++;
p->valores[p->topo]=valor;
}

/* Verifica se está vazia, se não estiver guarda o valor do topo em outra variável
decrementa o topo e retorna o valor que foi removido. Se estiver vazia retorna -1, 
porque se retornar 0 vai ser o valor 0 como se ele estivesse no topo da pilha
e isso pode causar confusão*/

int desempilhar(Pilha *p){
if(pilhaVazia(p)){
return -1;
}

int x;
x = p->valores[p->topo];
p->topo--;

return x;
}

/* Função main para testar a pilha*/

int main(){
Pilha *p;
p = criaPilha(5);
empilhar(p, 10);
empilhar(p, 20);
empilhar(p, 30);
printf("%d", desempilhar(p));
free(p->valores); // Libera a memória alocada para o vetor de valores
free(p); // Libera a memória alocada para a pilha
return 0;
}

/* Funções de uma pilha:
- Criar a pilha
- Verifica se está vazia
- Verifica se está cheia
- Empilha
- Desempilha
- Retorna o topo
*/
