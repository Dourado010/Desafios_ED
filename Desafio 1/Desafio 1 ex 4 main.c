#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};

// Cria novo nó
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

// Insere no início
struct no *insert_first(struct no *lista, int info) {
    struct no *novo = novoNo(info);
    novo->prox = lista;
    return novo;
}

// Insere no final
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

// Remove por valor
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

    // Valor não encontrado
    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", value);
        return lista;
    }

    anterior->prox = atual->prox;
    free(atual);

    return lista;
}

// Inverte a lista
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

// Imprime lista
void print_list(struct no *lista) {
    struct no *curr = lista;

    while (curr != NULL) {
        printf("%d -> ", curr->info);
        curr = curr->prox;
    }

    printf("NULL\n");
}

// Libera memória
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

    // Inserindo elementos
    lista = insert_first(lista, 30);
    lista = insert_first(lista, 20);
    lista = insert_first(lista, 10);

    lista = insert_last(lista, 40);
    lista = insert_last(lista, 50);

    printf("Lista inicial:\n");
    print_list(lista);

    // Reverter lista
    lista = reverse_list(lista);
    printf("\nLista invertida:\n");
    print_list(lista);

    // Liberar memória
    free_list(lista);

    return 0;
}