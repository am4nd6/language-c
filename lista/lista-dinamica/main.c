#include <stdio.h>
#include <stdlib.h>

/*
Na lista dinâmica, cria-se um ponteiro do tipo lista na main.
*/

typedef struct no{
    int valor; // Guarda apenas um valor
    struct no *proximo; //Guarda o endereço do próximo No
} No;

typedef struct lista{
    No *inicio; // Guarda o endereço do ponteiro que inicia a lista
    int tamanho; //Guarda o tamanho da lista total
} Lista;

// Retorna se lista existe

bool existe (Lista *l){
    return !(l == NULL);
}

/*
Para criar uma lista dinâmica, aloca uma memória, verifica se funcionou a alocação, e inicia a lista.
*/

Lista* criaLista(){
    Lista* l = malloc(sizeof(Lista));
    if(!existe(l)){
        return 0;
    }
    l->tamanho=0;
    l->inicio=NULL;
    return l;
}

/*
Para destruir uma lista dinâmica, a função recebe um ponteiro do tipo lista, verifica se ela tá vazia, se não estiver,
cria um auxiliar do tipo ponteiro de no, passa o endereço do início da lista para o auxiliar, 
cria um outro ponteiro que vai receber sempre o proximo do auxiliar, isso serve pra não modificar o que tem dentro
da lista, e verifica, enquanto auxiliar for diferente de null, o proximo recebe o proximo de auxiliar,
libera o auxiliar, e auxiliar recebe o proximo.
Repete isso até o final da lista e libera a lista.
*/

void destruirLista(Lista *l){
    if(!existe(l)){
        return;
    }
    No* aux;
    aux = l->inicio;
    No* proximo;
    while(aux != NULL){
        proximo = aux->proximo;
        free(aux);
        aux = proximo;

    }
    free(l);
}

/*
Para contar quantos elementos há na lista, a função recebe um ponteiro e retorna
o tamanho da lista.
*/

int contaLista(Lista *l){
    if(!existe(l)){
        return 0;
    }
    return l->tamanho;
}

/*
Para verificar se a lista está vazia, a função recebe um ponteiro e retorna
1 se a lista estiver vazia, ou 0 se não estiver. Para isso, deve se verificar
se o endereço do início da lista é nulo.
*/

int listaVazia(Lista *l){
    return !existe(l) || l->inicio == NULL;
}

/*
Retorna sempre falso, porque na lista dinâmica, depende da memória do computador pra saber se está cheia.
*/

int listaCheia(Lista *l){
    return 0;
}

/* Verifica se lista está vazia (se null também), se não, usa um auxiliar para navegar pelo while,
mostra na tela, depois incrementa o próximo, usando o auxiliar, depois retorna. */

void imprime(Lista *l){
    if(listaVazia(l)){
        return;
    }

    No *aux = l->inicio;
    
    while(aux != NULL){
        printf(" [%d]", aux->valor);
        aux = aux->proximo;
    }
    return;
}

/* Verifica se a lista não existe, cria um nó novo, verifica se a alocação deu certo,
acrescente o valor do nó, faz o apontamento. Verifica se a lista tá vazia, se tiver acrescenta
ao incio da lista, se não, percorre toda a lista com um auxiliar, depois pare antes do próximo ponteiro do
auxiliar for nulo e aí adiciona a esse próximo (quando for nulo) o endereço do novo nó,
incrementa tamanho e assim retorna o 1 */

int insereFinal(Lista* l, int valor){
    if(!existe(l)){
        return 0;
    }

    No* novo = malloc(sizeof(No));
    if(!existe(novo)){
        return NULL;
    }
    
    novo->valor = valor;
    novo->proximo = NULL;

    if(listaVazia(l)){
        l->inicio = novo;
      
    } else{
        No* aux = l->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    l->tamanho++;
    return 1;
}

/*oiiiiiii  */

int inserePos(Lista* l){
    if(listaVazia(l)){
        return 0;
    }
}

/*  */

buscaPos()

/*  */

buscaTodasAchadas()

/*  */

buscaPrimeiraAchado()

/*  */

removePos()

/*  */

removeTodasAsPos()

/*  */

removePrimeiraPos()

/*  */

main()


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
