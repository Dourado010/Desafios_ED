#include<stdio.h>
#include<stdlib.h>

struct no {
    int info;         
    struct no * prox;
};

struct no * novoNo(int info) {
    struct no * novo = malloc(sizeof(struct no));
    novo->info = info;
    return novo;
}

struct no * insert_first(struct no * lista, int info) {
    struct no *novo = novoNo(info);
    if (!novo) return lista;   // se falhar, mantém a lista como estava
    novo->prox = lista;        // novo aponta para a antiga cabeça
    return novo;               // novo vira a cabeça
}

void insert_last(struct no * lista, int info) {
    struct no *novo = novoNo(info);
    // Precisamos encontrar o último elemento da lista. Quando encontramos, adicionamos o novo!
    struct no *curr = lista;
    while (curr->prox != NULL) {
        curr = curr->prox;
    }
    curr->prox = novo;
}

struct no * remove_first(struct no * lista) {
    if (lista == NULL) return NULL; // lista vazia

    struct no *novo_inicio = lista->prox;
    return novo_inicio;
}

/*
Criei a função print_list como pediu o exercício para passar pela lista 
e imprimir ela. Passei void como retorno porque a função não precisa 
retornar nenhum valor de fato, ela só vai fazer a ação de imprimir 
os valores da lista. 

Aí coloquei como parâmetro o struct no *lista que vai apontar para o primeiro
elemento da lista. 

Depois comecei a função com struct no *curr = lista, fazendo com que o ponteiro 
do elemento atual seja igual ao primeiro da lista.. 

Aí eu fiz um while para fazer o loop até que curr, o elemento atual, seja nulo
e nesse while eu fiz a impressão da informação dentro do nó atual, depois 
foi só colocar o elemento atual recebendo o elemento atual apontando para o 
próximo da lista.
 
E no final coloquei um print null só para ficar mais fácil para mim de entender 
como a lista ligada funciona.
*/

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

    lista = insert_first(lista, 10);
    lista = insert_first(lista, 20);
    lista = insert_first(lista, 30);

    print_list(lista);

    return 0;
}