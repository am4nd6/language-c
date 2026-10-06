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

/* Recebe uma lista, uma posição e um valor. Verifica se a lista existe e se a posição é válida.
SE estiver tudo certo, aloca uma memória para o novo nó, verifica se a locação funcionou.
Se funcionou, coloca o valor do novo nó e aponta ele para null. Verifica se a posição é 0 
(aqui não verifica se a lista tá vazia porque mesmo se tivesse vazia, a posição seria 0),
além disso, se a lista estiver vazia e a posição for maior, ele já no primeiro if.
Se a posição for igual a 0, então ele só adiciona o nó novo no início da lista e proóximo do nó aponta para o
para o próximo do auxiliar.
Se não for igual a 0, usa um for que vai de 0 até a posição inserida - 1. Deve parar no antepenúltimo.
Pois, o auxiliar já aponta para o penúltimo, saindo do for, o próximo do novo deve apontar pro próximo
do auxiliar, pois agora ele vai está apontando para o nó da posição certa. Depois apontar, o 
próximo do penúltimo nó, para o novo nó, por fim, acrescentar +1 ao tamanho. */

int inserePos(Lista* l, int pos, int valor){
    if(!existe(l) || pos<0 || pos>l->tamanho){
        return 0;
    }

    No* novo = malloc(sizeof(No));

    if(!existe(novo)){
        return 0;
    }

    novo->valor = valor;
    novo->proximo = NULL;
    No* aux = l->inicio;

    if(pos==0){
        l->inicio = novo;
        novo->proximo = aux;
    } else {
        for(int i=0 ; i<pos-1; i++){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    l->tamanho++;
    return 1;
}

/* Verifique se a lista existe e se a posição é válida.
Como você vai retornar posição, lembre-se de SEMPRE diminuir -1 para poder retornar o 
amanho verdadeiro das posições, lembre-se que elas sempre começam na posição 0. 
Lembre-se de retornar sempre -1 ao invés de 0, para falso. 
Depois, verifique se a lista está vazia. Se não estiver, crie um nó para auxiliar e faça ele receber
o endereço da lista. Depois faça um for para fazer o auxilio receber o próximo, fazendo isso,
retorne o valor da posição pedida.
*/

int buscaPos(Lista* l, int pos){
    if(!existe(l) || pos<0 || pos>l->tamanho-1){
        return -1;
    }

    if(listaVazia(l)){
        return -1;
    }

    No* aux = l->inicio;
    for(int i = 1; i <= pos; i++){
        aux = aux->proximo;
    }
    return aux->valor;
}

/* Recebe um ponteiro do tipo lista e um valor. Verifica se a lista existe e é válida.
Se for, cria um nó auxiliar, um for começando da posição 0 e indo até tamanho-1, vai procurar se o valor
do nó é igual ao valor inserido e se for retorna a posição achada. Ou seja, esta função 
retorna a primeira posição em que o valor inserido foi achado. */

int buscaPrimeiraAchado(Lista* l, int valor){
    if(listaVazia(l)){
        return -1;
    }

    No* aux = l->inicio;

    for(int i = 0; i<=l->tamanho-1; i++){
        if(aux->valor==valor){
            return i;
        }
        aux = aux->proximo;
    }
    return -1;
}

/* Recebe um ponteiro do tipo lista e um valor. Verifica se a lista existe e é válida.
Se for, cria uma nova lista, verifica se ele existe, se existir, cria um nó auxiliar e um verificador, 
um for começando da posição 0 e indo até tamanho-1, vai procurar se o valor
do nó é igual ao valor inserido e se for insere na lista a posição achada. 
Incrementa o verificador, que vai servir pra definir o tipo de retorno, se encontrado, retorna a lista
se não libera a lista e retorna null. */

Lista* buscaTodasAchadas(Lista* l, int valor){
    if(listaVazia(l)){
        return NULL;
    }

    Lista* p = criaLista();
    if(!existe(p)){
        return NULL;
    }

    No* aux = l->inicio;
    int encontrei = 0;

    for(int i = 0; i <= l->tamanho -1; i++){
        if(aux->valor == valor){
            insereFinal(p, i);
            encontrei = 1;
        }
        aux = aux->proximo;
    }
    if(encontrei == 1){
        return p;
    }
    free(p);
    return NULL;
}

/* Verifica se a lista e a posição são válidas. Crie um ponteiro auxiliar para pecorrer a lista.
crie um outro ponteiro para receber o ponteiro que deve ser removido. Verifica se a posição é a inicial,
se for faz o início apontar para o próximo do auxiliar. Se não, cria um outro ponteiro para pular 
o ponteiro que deve ser removido, pecorra a lista e o auxiliar para no penúltimo,
antes da posição que deve ser removida. Enquanto isso "prox" sempre recebe um ponteiro posterior.
Depois disso, removido recebe o prox, porque ele vai parar justamente na posição que deve ser removida, prox recebe
o ponteiro depois do que deve ser removido, e aux passar a receber prox, depois libera o removido e por fim, remover mais um do tamanho total da lista.
 */

int removePos(Lista* l, int pos){
    if(listaVazia(l) || pos<0 || pos>=l->tamanho){
        return 0;
    }

    No* aux = l->inicio;
    No* removido;
    if(pos == 0){
        l->inicio=aux->proximo;
        removido = aux;
    }
    else {

        No* prox = aux->proximo;

        for(int i = 0; i<pos-1; i++){
            aux=aux->proximo;
            prox=aux->proximo;
        }
        removido = prox;
        prox = prox->proximo;
        aux->proximo=prox;
    }

    free(removido);
    l->tamanho--;                           

    return 1;
}

/* Verifica se a lista é válida. Chama a função para buscar a primeira posição achada em que existe o valor passado,
verifica se o x!=1 e se não for, chama a função de remover na posição do x */

int removePrimeiraPos(Lista* l, int valor){
    if(listaVazia(l)){
        return 0;
    }

    int x = buscaPrimeiraAchado(l, valor);
    if(x!=-1){
        removePos(l, x);
        return 1;
    }

    return 0;
}


/*  fgbhfghrfhgjfgfgffdfhf terminarrrrrrrrr
Receber um valor e remover todas as posições achadas 

*/

int removeTodasAsPos(Lista* l, int valor){
    if(listaVazia(l)){
        return 0;
    }

    Lista* p = buscaTodasAchadas(l, valor);
    
    if(listaVazia(p)){
        retun 0;
    }

    No* aux = p->inicio;
    while(aux!=NULL){
        removePos(l, aux->valor);
        aux=aux->proximo;
    }
    return 1;
}

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
