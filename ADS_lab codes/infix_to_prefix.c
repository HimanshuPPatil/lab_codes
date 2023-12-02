#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define MAX 20

void infixtoprefix(char infix[20],char prefix[20]);
char pop();
void push(char symbol);
int precedence(char symbol);

int top=-1;
char stack[MAX];

int main()
{
	char infix[20],prefix[20],temp;
	printf("Enter infix operation: ");
	scanf("%s",infix);
	printf("\n\n");
	infixtoprefix(infix,prefix);
	printf("%s",strrev(prefix));
	printf("\n\n");
    return 0;
}

void infixtoprefix(char infix[20],char prefix[20])
{
	int i,j=0;
	char symbol;
	infix=strrev(infix);
	for (i=0;i<strlen(infix);i++)
    {
		symbol=infix[i];
		if(isalnum(symbol))
		{
			prefix[j]=symbol;
			j++;
		}
        else
        {
			if (symbol==')')
			{
				push(symbol);
			}
            else if(symbol == '(')
            {
				while (stack[top]!=')')
				{
					prefix[j]=pop();
					j++;
				}
				pop();
			}
            else
            {
				if (precedence(stack[top])<=precedence(symbol))
				{
					push(symbol);
				}
                else
                {
					while(precedence(stack[top])>precedence(symbol))
					{
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				}
			}
		}
	}

	while(top!=-1)
    {
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

void push(char symbol)
{
	stack[++top]=symbol;
}
int precedence(char symbol)
{
	switch(symbol)
	{
		case '+':
        case '-':
		        return 2;
                break;
		case '*':
        case '/':
		        return 3;
                break;
        case '^':
		        return 4;
                break;
        case '(':
        case ')':
		        return 1;
                break;
	}
}

