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

    // Remove primeiro
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

    // Não encontrou
    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", value);
        return lista;
    }

    anterior->prox = atual->prox;
    free(atual);

    return lista;
}

void print_list(struct no *lista) {
    struct no *curr = lista;

    while (curr != NULL) {
        printf("%d -> ", curr->info);
        curr = curr->prox;
    }

    printf("NULL\n");
}

int main() {
    struct no *lista = NULL;

    // Inserindo elementos
    lista = insert_first(lista, 30);
    lista = insert_first(lista, 20);
    lista = insert_first(lista, 10);

    lista = insert_last(lista, 40);
    lista = insert_last(lista, 50);

    printf("Lista inicial:\n");
    print_list(lista);

    // Removendo valor
    lista = remove_value(lista, 30);

    printf("\nDepois de remover 30:\n");
    print_list(lista);

    return 0;
}