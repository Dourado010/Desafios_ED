#include<stdio.h> 
#include <stdlib.h>

/** Definição de estruturas **/

typedef struct no {
    int info;
    struct no * prox;
} No;

typedef No * Celula;

typedef struct lista {
    Celula inicio;
    Celula fim;
} Lista;

typedef Lista * ListaLigada;

// ----------------------------- //

/**
 Vamos usar o prefixo ll para todas as funções que são de Lista Ligada (dois l's)
*/

ListaLigada novaLista() {
    ListaLigada l = malloc(sizeof(Lista));
    if (!l) return NULL;
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

Celula novaCelula(int info) {
    Celula celula = (Celula) malloc(sizeof(No));
    celula->info = info;
    celula->prox = NULL;

    return celula;
}

void llPrint(ListaLigada lista) {
    for (Celula aux = lista->inicio; aux != NULL; aux = aux->prox) {
        printf("%d", aux->info);
        if (aux->prox != NULL)
            printf(" -> ");
    }
    printf("\n");
}

/*
    Busca uma Celula a partir de info, retornando seu ponteiro
*/
Celula llBusca(ListaLigada lista, int info) {
    for (Celula aux = lista->inicio; aux != NULL; aux = aux->prox) {
        if (aux->info == info) {
            return aux;
        }
    }
    return NULL;
}

Celula llGetPenultimo(ListaLigada lista) {
    if (lista->inicio == NULL) {
        return NULL;
    }

    Celula penultimo = NULL;
    for(Celula aux = lista->inicio; aux->prox != NULL; aux = aux->prox) {
        penultimo = aux;
    }
    return penultimo;
}

void llInsereNoInicio(ListaLigada lista, int info) {
    Celula celula = novaCelula(info);
    if (lista->inicio == NULL) { // lista é vazia
        lista->inicio = celula;
        lista->fim = celula;
    }
    else {
        celula->prox = lista->inicio;
        lista->inicio = celula;
    }
}

void llInsereNoFim(ListaLigada lista, int info) {
    Celula nova = novaCelula(info);
    
    if (lista->inicio == NULL) { // ou seja, a lista está vazia
        lista->inicio = nova;
        lista->fim = nova;
        return;
    }
    lista->fim->prox = nova;
    lista->fim = nova;
}

void llRemoveInicio(ListaLigada lista) {
    if (lista->inicio == NULL) {
        return;
    }

    Celula removido = lista->inicio;
    lista->inicio = removido->prox;
    free(removido); // liberando o ponteiro da Celula removida
}

void llInsereDepoisDe(ListaLigada lista, int alvo, int info) {
    Celula nova = novaCelula(info);
    Celula buscada = llBusca(lista, alvo);
    if (buscada != NULL) { // encontrou!
        nova->prox = buscada->prox;
        buscada->prox = nova;
    }
    else {
        llInsereNoFim(lista, info);
        free(nova);
    }
}

void llInsereAntesDe(ListaLigada lista, int alvo, int info) {
    Celula nova = novaCelula(info);
    Celula aux = NULL;
    for (aux = lista->inicio; aux->prox != NULL && aux->prox->info != alvo; aux = aux->prox);
    if (aux->prox != NULL) { // encontrou!
        nova->prox = aux->prox;
        aux->prox = nova;
    }
    else {
        llInsereNoInicio(lista, info);
        free(nova);
    }
}

/*
    Remove uma Celula específica da Lista, baseado em seu valor info
*/
Celula llRemove(ListaLigada lista, int alvo) {
    Celula aux = NULL;
    for (aux = lista->inicio; aux->prox != NULL && aux->prox->info != alvo; aux = aux->prox);
    if (aux != NULL) { // aux é a celula anterior ao no que quero remover
        Celula removido = aux->prox;
        aux->prox = aux->prox->prox;
        free(removido);
    }
    
    return NULL; // Não consegui fazer nada, retorna nulo...
}

void llRemoveFim(ListaLigada lista) {
    Celula penultimo = llGetPenultimo(lista);
    Celula removido = lista->fim;
    lista->fim = penultimo;
    penultimo->prox = NULL;
    free(removido);
}

/*

    Criei uma função insereOrdenado retornando void pois não irá retornar um 
    valor, passei como parâmetro: listaligada lista pois irá percorrer a lista 
    igual aos outros exercícios, e passei uma variável valor que será o valor 
    que vamos adicionar. 
    
    Comecei a função passando celula nova = nova celula para criar essa nova
    celula que terá um valor qualquer. 
    
    Fiz um if para saber se a lista está vazia, se sim a nova célula será igual 
    ao inicio e ao fim da lista e retorna a lista. 
    
    embaixo fiz outro if para saber se o valor é menor que o valor inicial da 
    lista assumindo que a lista tem algum valor, e se for menor o novo nó aponta
    para o antigo início e o início da lista passa a ser o novo nó, e novamente
    retorna a lista.
    
    Aí eu fiz celula aux = lista -> inicio, que vai ser um ponteiro auxiliar 
    para começar no inicio e percorrer a lista. 
    
    criei um while para rodar enquanto o próximo for diferente de null e 
    o valor do próximo for menor que o valor escolhido, o anterior é o próximo
    e aí o valor escolhido vai para o final. 
    
    depois eu fiz o novo nó apontar para o próximo depois do auxiliar 
    e aí na linha de baixo o próximo aponta para o novo.
    
    e aí para finalizar se o próximo da nova é igual a null, ou seja, a nova 
    célula é a final ele vai atualizar o ponteiro do fim. 
    

*/

void insereOrdenado(ListaLigada lista, int valor) {

    Celula nova = novaCelula(valor);

    if (lista->inicio == NULL) {
        lista->inicio = nova;
        lista->fim = nova;
        return;
    }

    if (valor < lista->inicio->info) {
        nova->prox = lista->inicio;
        lista->inicio = nova;
        return;
    }

    Celula aux = lista->inicio;

    while (aux->prox != NULL && aux->prox->info < valor) {
        aux = aux->prox;
    }

    nova->prox = aux->prox;
    aux->prox = nova;

    if (nova->prox == NULL) {
        lista->fim = nova;
    }
}

int main() {

    ListaLigada lista = novaLista();
    
    printf("Lista no começo: ");
    printf("\n");
    llInsereNoInicio(lista, 5);
    llInsereNoFim(lista, 2);
    llInsereNoFim(lista, 8);
    llInsereNoFim(lista, 1);
    llInsereNoFim(lista, 4);
    llInsereNoFim(lista, 7);
    
    
    llPrint(lista);

    ListaLigada lista2 = novaLista();
    printf("\n");
    printf("Lista depois da função: ");
    printf("\n");
    insereOrdenado(lista2, 5);
    insereOrdenado(lista2, 2);
    insereOrdenado(lista2, 8);
    insereOrdenado(lista2, 1);
    insereOrdenado(lista2, 4);
    insereOrdenado(lista2, 7);

    llPrint(lista2);

    return 0;
}