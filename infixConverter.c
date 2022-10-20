#include<stdio.h>
#include<ctype.h>

char pilha[100];
int topo = -1;

void push (char a)
{
    pilha[++topo] = a;
}

char pop()
{
    if(topo == -1)
        return -1;
    else
        return pilha[topo--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char expressão[100];
    char *e, x;
    printf("digite a expressão: ");
    scanf("%s", expressão);
    printf("\n");
    e = expressão;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(pilha[topo]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }

    while(topo != -1)
    {
        printf("%c ",pop());
    }
    printf("\n");
}