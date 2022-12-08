#include <stdio.h>
#include <stdlib.h>

//Alunos:
// Guilherme Leite Félix
// Amadeu Mateus de Vasconcelos Neto

// Estrutura de um nó da lista
typedef struct List_{
    struct List_ *prev;
    int value;
    struct List_ *next;
}List;

// Função para criar um nó
List* makeNode(int value){
    List *n = malloc(sizeof(List));
    n->prev = NULL;
    n->value = value;
    n->next = NULL;
    return n;
}

// Função para inserir um nó no início da lista
List *makeNum(List *num, int value){
    List *tmp = makeNode(value);
    tmp->next = num;
    num->prev = tmp;
    return tmp;
}


// Função para multiplicar duas listas
long long multiply(List *first, List *second){
    long long  N = 100000007;
    long long  num1 = 0, num2 = 0;

    while (first || second) {
        if (first) {
           num1 = ((num1)*10)%N + first->value;
           first = first->next;
        }

        if (second) {
            num2 = ((num2)*10)%N + second->value;
            second = second->next;
        }
    }
    return ((num1%N)*(num2%N))%N;
}

// Função para imprimir uma lista
void printList(List* list){
    while(list){
        printf("%d", list->value);
	    list = list->next;
    }
}

int main(void){
    List *num, *tmp, *tmp2, *num2;
    List *uni = makeNode(9);
    List *uni2 = makeNode(4);

    num = uni;
    num = makeNum(num, 4);

    num2 = uni2;
    num2 = makeNum(num2, 7);

    tmp = num;
    tmp2 = num2;

    printList(tmp);
    printf("\n");
    printList(tmp2);

    printf("\n");

    long long  result = multiply(num, num2);
    printf("Resultado: %lli", result);

    printf("\n");
}