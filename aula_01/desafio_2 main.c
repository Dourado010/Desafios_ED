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

/* 
Nesse exercício criei a função remove_last para remover o último elemento da 
lista como o exercício tinha pedido e foram feitos os devidos testes na main.

Aqui usei antes da função struct no * porque ao remover um elemento da
lista pode ser necessário alterar o início da lista. se a lista tiver apenas 
um elemento, ao removê-lo a lista ficará vazia,então o início da lista passará 
a ser NULL.Por isso a função precisa retornar o novo ponteiro para o início 
da lista. 

Aí passei como parâmetro struct no *lista que aponta para o primeiro elemento
da lista assim como o primeiro exercício. 

Depois eu dividi a função em três casos: sendo um deles com a lista vazia, 
um com a lista com um elemento só e um caso geral.

Quando a lista for vazia ele retorna null pois não tem lista.
Quando a lista tem um elemento ele também retorna null pois ele removeu
esse único elemento, que é o primeiro e o último elemento. Aí eu fiz se o
próximo da lista for null eu esvazio a lista e retono null.
E no caso geral comecei do mesmo modo que o exercício 1, com o 
struct no *curr = lista que é para o ponteiro atual começar no início da lista, 
e fiz um while para achar o penúltimo elemento da lista, já que a lista não 
vai do fim para o começo o jeito que achei de remover o último foi indo até o 
penúltimo, no caso o while vai continuar rodando enquanto o próximo nó ainda
tiver outro nó depois dele. aí o curr vai para o próximo. Aí quando o while 
termina o curr está no penúltimo então eu fiz free curr -> prox para limpar
o último da lista, aí eu fiz curr -> prox = null para indicar que ele agora 
é vazio e depois retorna a listaa pois o início da lista não é alterado no caso 
geral.

E aí fiz os testes na main também assim como o exercício pediu.


*/

struct no *remove_last(struct no *lista) {

    if (lista == NULL) {
        return NULL;
    }
    
    if (lista->prox == NULL) {
        free(lista);
        return NULL;
    }

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
    

    printf("\nDepois de remover o último:\n");
    print_list(lista);

    return 0;
}