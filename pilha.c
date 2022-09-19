#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 200

typedef struct Pilha {
    int topo;
    float dados[SIZE];
}Pilha;

void push(Pilha *pilha, char *token);
float pop(Pilha *pilha);

void push(Pilha *pilha, char *token){
    pilha->topo++;
    pilha->dados[pilha->topo] = atof(token);
}

float pop(Pilha *pilha){
    return pilha->dados[pilha->topo--];
}

int main (int argc, char *argv[])
{
    // char expressao[SIZE] = "1337 202 + 300 501 * +";
    char expressao[SIZE];
    Pilha pilha;
    pilha.topo = -1;
    char num[10];

    printf("digite a expressão: \n");
    scanf("%[^\n]s", expressao);

    char *token = strtok(expressao, " ");

    while(token != NULL){
        if(isdigit(*token)){
            push(&pilha, token);
        }else {
            float num1 = pop(&pilha);
            float num2 = pop(&pilha);
            switch (*token) {
                case '+':
                {
                    sprintf(num, "%.2f", num1 + num2);
                    break;
                }
                case '-':
                {
                    sprintf(num, "%.2f", num1 - num2);
                    break;
                }
                case '*':
                {
                    sprintf(num, "%.2f", num1 * num2);
                    break;
                }
                case '/':
                {
                    sprintf(num, "%.2f", num2 / num1);
                    break;
                }
            }
            push(&pilha, num);
        }
        token = strtok(NULL, " ");
    }
    printf("resultado: %.2f\n", pop(&pilha));
}
