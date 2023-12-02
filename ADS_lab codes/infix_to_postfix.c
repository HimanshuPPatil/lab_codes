#include<stdio.h>
#include<string.h>
#include<ctype.h>
int top=-1;
char stack[10];
int priority(char k)
{
    switch(k)
    {
        case '+':
        case '-':
           return 1;
           break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        case '(':
            return 0;
            break;
        default:
            return 0;
    }
}
char pop()
{
    char k;
    k=stack[top];
    top--;
    return k;
}
void push(char x)
{
    top++;
    stack[top]=x;
}
int main()
{
    char expression[30],*expe,x;
    printf("enter infix expression");
    scanf("%s",expression);
    expe=expression;
    while(*expe != '\0')
    {
        if(isalnum(*expe))
            printf("%c",*expe);
        else if(*expe=='(')
           push(*expe);
        else if(*expe==')')
        {
            while((x=pop()) != '(')
               printf("%c",x);
        }
        else
        {
            while(priority(stack[top])>=priority(*expe))
                printf("%c",pop());
            push(*expe);
        }
        expe++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}


