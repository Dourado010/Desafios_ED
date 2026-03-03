/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};

struct no *novoNo(int info) {
    struct no *novo = (struct no*) malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    novo->info = info;
    novo->prox = NULL;
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

void print_list(struct no *lista) {
    struct no *curr = lista;
    while (curr != NULL) {
        printf("%d -> ", curr->info);
        curr = curr->prox;
    }
    printf("NULL\n");
}

struct no *remove_last(struct no *lista) {

    // Caso 1: lista vazia
    if (lista == NULL) {
        return NULL;
    }

    // Caso 2: apenas um elemento
    if (lista->prox == NULL) {
        free(lista);
        return NULL;
    }

    // Caso geral
    struct no *curr = lista;

    while (curr->prox->prox != NULL) {
        curr = curr->prox;
    }

    free(curr->prox);
    curr->prox = NULL;

    return lista;
}

int main() {

    struct no *lista = NULL;

    lista = insert_last(lista, 10);
    lista = insert_last(lista, 20);
    lista = insert_last(lista, 30);
    lista = insert_last(lista, 40);
    lista = insert_last(lista, 50);

    printf("Lista original:\n");
    print_list(lista);

    lista = remove_last(lista);
    lista = remove_last(lista);
    lista = remove_last(lista);
    lista = remove_last(lista);
    lista = remove_last(lista);

    printf("\nDepois de remover o último:\n");
    print_list(lista);

    return 0;
}