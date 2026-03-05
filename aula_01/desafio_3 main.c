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

/*

Criei a função remove_value como o exercício pedia e com os parâmetros que
ele também pedia.

Fiz o caso de a lista estar vazia igual ao exercício anterior, e aí ela retorna
null. 

Fiz um if lista -> info == value para verificar se o valor que queremos remover 
é o primeiro da lista, nesse caso se o primeiro nó contém o valor que 
queremos remover, então o segundo nó da lista passará a ser o novo início.
por isso criei o novo_inicio = ao elemento depois do primeiro ou seja o segundo.
aí fiz um free na lista para remover o primeiro da lista e ele retorna o valor, 
do novo inicio. 

Se o valor que queremos remover não for o primeiro, então precisamos percorrer
a lista inteira e para isso criei dois ponteiros auxiliares, sendo eles o 
anterior e o atual. o anterior apontando para o primeiro da lista e o atual 
apontando para o próximo elemento.

aí fiz um while para rodar enquanto atual for diferente de null ou seja não 
chegou no final da lista e se a informação do atual for diferente de value, ou 
seja não queremos remover esse valor. 

os ponteiros avançam pela lista com anterior = atual e atual = atual -> prox
e se atual for igual a null, ou seja se chegar no final e não removemos nenhum
valor, então o valor não foi encontrado. E ele retorna a lista. 

mas se o valor foi encontrado, eu fiz um anterior -> prox = atual -> prox 
e free atual para remover esse valor, e no fim retorno a lista.

*/

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

    lista = insert_first(lista, 30);
    lista = insert_first(lista, 20);
    lista = insert_first(lista, 10);

    lista = insert_last(lista, 40);
    lista = insert_last(lista, 50);

    printf("Lista inicial:\n");
    print_list(lista);

    lista = remove_value(lista, 30);

    printf("\nDepois de remover 30:\n");
    print_list(lista);

    return 0;
}