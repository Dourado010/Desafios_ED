#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};

struct no *novoNo(int info) {
    struct no *novo = malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    novo->info = info;
    novo->prox = NULL;
    return novo;
}

struct no *insert_first(struct no *lista, int info) {
    struct no *novo = novoNo(info);
    novo->prox = lista;
    return novo;
}

struct no *insert_last(struct no *lista, int info) {
    struct no *novo = novoNo(info);

    if (lista == NULL) {
        return novo;
    }

    struct no *curr = lista;
    while (curr->prox != NULL) {
        curr = curr->prox;
    }

    curr->prox = novo;
    return lista;
}

struct no *remove_value(struct no *lista, int value) {

    if (lista == NULL) {
        return NULL;
    }

    if (lista->info == value) {
        struct no *novo_inicio = lista->prox;
        free(lista);
        return novo_inicio;
    }

    struct no *anterior = lista;
    struct no *atual = lista->prox;

    while (atual != NULL && atual->info != value) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", value);
        return lista;
    }

    anterior->prox = atual->prox;
    free(atual);

    return lista;
}

/* 

fiz a função reverve_list igual o exercício pedia e com os mesmos parâmetros
como o exercício pediu

depois criei o ponteiro anterior guardando o nó anterior ao atual durante
a inversão, depois de forma semelhante aos outros exercícios criei o ponteiro
atual apontando para o começo da lista e criei o ponteiro próximo guardando
o nó posterior ao atual. 

aí criei um while para rodar enquanto o atual for diferente de null, ou seja,
enquanto não estiver no final da lista, e ele percorre a lista. 

aí guardei o próximo nó da lista dentro da variável próximo, e na parte 
atual -> prox = anterior é onde acontece a inversão, o ponteiro prox do nó
atual passa a apontar para o nó anterior, aí no anterior = atual eu atualizei 
o ponteiro atual e no atual = proximo eu avanço a lista e o ponteiro atual
aponta para o nó anterior.

E quando o while termina o ponteiro anterior estará agora apontando para o 
primeiro elemento da lista invertida e aí eu retornei ele.

*/

struct no *reverse_list(struct no *lista) {

    struct no *anterior = NULL;
    struct no *atual = lista;
    struct no *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

void print_list(struct no *lista) {
    struct no *curr = lista;

    while (curr != NULL) {
        printf("%d -> ", curr->info);
        curr = curr->prox;
    }

    printf("NULL\n");
}

void free_list(struct no *lista) {
    struct no *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

int main() {

    struct no *lista = NULL;

    lista = insert_first(lista, 30);
    lista = insert_first(lista, 20);
    lista = insert_first(lista, 10);

    lista = insert_last(lista, 40);
    lista = insert_last(lista, 50);

    printf("Lista inicial:\n");
    print_list(lista);

    lista = reverse_list(lista);
    printf("\nLista invertida:\n");
    print_list(lista);

    free_list(lista);

    return 0;
}