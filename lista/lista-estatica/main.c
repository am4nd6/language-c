#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Criado um ponteiro do tipo Lista na main e passado para as funções.

/*Para criar uma lista estática, você deve usar um vetor com uma constante global para definir o tamanho máximo.
E uma variável para saber o tamanho real que tem no vetor, porque o MAX define o máximo, mas tamanho o tamanho real dentro desse máximo.*/

typedef struct lista{
int valores[MAX];
int tamanho;
} Lista;

/*Para criar uma lista estática, primeiros alocamos um espaço na memória, verificamos se deu certo a alocação,
passamos o tamanho como sendo 0 e retorna a lista*/

Lista* criaLista(){
Lista* s;
s = malloc(sizeof(Lista));
if(s==NULL){
return NULL;
}
s->tamanho=0;
return s;
}

/*Para destruir a lista, basta passar o endereço da lista e liberar o espaço alocado na memória*/

void destroiLista(Lista *l){
free(l);
}

/*A função conta retorna o tamanho real que tem no vetor*/

int conta(Lista* l){
return l->tamanho;
}

/*A função vazia verifica se a lista está vazia, se o tamanho for 0 então está vazia*/

int vazia(Lista *l){
return l->tamanho==0;
}

/*A função cheia verifica se a lista está cheia, se o tamanho for igual ao máximo então está cheia*/

int cheia(Lista *l){

return l->tamanho==MAX;

}

/*A função imprime, verifica se está vazia, se não estiver imprime os valores da lista*/

void imprime(Lista *l){
if(vazia(l)){
return;
}
for(int i=0; i<l->tamanho; i++){
printf("%d\n", l->valores[i]);
}
}

/*A função insereFinal, verifica se está cheia, se não estiver, insere o valor no final*/

int insereFinal(Lista* l, int valor){
if(cheia(l)){
return 0;
}
l->valores[l->tamanho]= valor;
l->tamanho++;
return 1;
}

/*A função inserePos, verifica se está cheia, se não estiver, verifica se a posição passada
está válida, se estiver verifica se está vazia
se estiver vazia, insere o valor no final, caso contrário, insere o valor na posição desejada*/

int inserePos(Lista *l, int valor, int pos){
if(cheia(l)){
return 0;
}


if(pos>l->tamanho || pos<0){
return 0;
}

if(vazia(l)){
return insereFinal(l, valor);
}

for(int i=l->tamanho; i>pos; i--){
l->valores[i]=l->valores[i-1];
}
l->tamanho++;
l->valores[pos]=valor;
return 1;
}

/*A função removePos, verifica se está vazia ou se a posição passada não é válida, se não estiver, 
verifica se a posição não é o final, se não for, remove o valor da posição desejada*/

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

/*
Remove todas as posições em que o valor for encontrado. 
*/

int removeTodosValores(Lista *l, int valor){
    if(vazia(l)){
        return 0;
    }

int encontrei = 0;
    for(int i=0; i<l->tamanho; i++){
        if(l->valores[i]==valor){
            removePos(l, i);
            encontrei = 1;
            i=-1;
        }
    }
    return encontrei;
}

/*
Remover a primeira posição em que o valor for encontrada. 
*/

int removePrimeiroValor(Lista *l, int valor){
    if(vazia(l)){
            return 0;
        }

        for(int i=0; i<l->tamanho; i++){
            if(l->valores[i]==valor){
                removePos(l, i);
                return 1;
            }
        }
        return 0;

}


/*
Verifica a lista tá vazia e se a posição é válida, se caso positivo, retorna o valor da posição passada.
*/

int* buscaPos(Lista *l, int pos){
if(vazia(l) || pos>=l->tamanho || pos<0){
    return NULL;
}
return &l->valores[pos];
}

/*
A função buscaValor, passa a lista e um valor,  verifica se está vazia
se não estiver, percorre a lista, se encontrar o valor, retorna todas as posições em que esse valor
tenha na lista, caso contrário, retorna -1
*/

Lista* buscaTodosValores(Lista *l, int valor){
if(vazia(l)){
return NULL;
}
Lista *p = criaLista();
if(p==NULL){
    return NULL;
}

for(int i=0; i<=l->tamanho-1; i++){
if(l->valores[i]==valor){
    p->valores[p->tamanho]=i;
    p->tamanho++;
}
}
if(p->tamanho==0){
    destroiLista(p);
    return NULL;
}
return p;
}

/*
A função buscaValor, passa a lista e um valor, verifica se está vazia
se não estiver, percorre a lista, se encontrar o valor, retorna a primeira posição em que esse valor foi encontrado
na lista, caso contrário, retorna -1
*/

int buscaPrimeiroValor(Lista *l, int valor){
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

int main(){
    Lista *l = criaLista();
    if(l==NULL){
        return 1;
    }
    insereFinal(l, 10);
    insereFinal(l, 20);
    insereFinal(l, 30);
    insereFinal(l, 40);
    insereFinal(l, 50);
    imprime(l);
    removePos(l, 2);
    imprime(l);
    Lista *p = buscaTodosValores(l, 20);
    if(p==NULL){
        destroiLista(l);
        return 1;
    }
    imprime(p);
    destroiLista(p);
    destroiLista(l);
    return 0;
}

/* Funções de uma lista estática:
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