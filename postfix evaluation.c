#include <stdio.h>

int size=1000, top=-1;
int stack[1000];

void push(int n)
{
    stack[++top]=n;
}

int pop()
{
    return stack[top--];
}

int isoperand(char ch)
{
    return (ch>='0'&& ch<='9');
}

void display()
{
    for (int i=top; i>=0; i--)
    {
        printf("%d\n",stack[i]);
    }
    printf("\n");
}

int eval(int a, int b, char ch)
{
    switch (ch)
    {
        case '+': return (a+b);
        case '-': return (a-b);
        case '*': return (a*b);
        case '/': return (a/b);
        default: return -1;
    }
}

int main()
{
    char postfix[size];
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    int i=0;
    while (postfix[i]!='\0')
    {
        char ch=postfix[i];
        if(isoperand(ch))
        {
            push(ch-'0');
        }
        else
        {
            push(eval(pop(),pop(),ch));
        }
        i++;
    }
    printf("Result is %d",pop());
    return 0;
}

// 252-3/+4+ -> 7