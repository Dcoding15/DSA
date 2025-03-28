#include<stdio.h>

int top=-1, size=1000;
char stack[1000];


char push(int n)
{
    if (top==size-1)
    {
        return '0';
    }
    else
    {
        stack[++top]=n;
        return '1';
    }
}

char pop()
{
    if (top==-1)
    {
        return '0';
    }
    else
    {
        stack[--top];
        return '1';
    }
}

char seek()
{
    if (top==-1)
    {
        return '0';
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    char expr[size];
    int flag=0;
    printf("Enter expression: ");
    scanf("%s",&expr);
    for (int i=0; i<size; i++)
    {
        if (expr[i]=='(')
        {
            push(expr[i]);
        }
        else
        {
            if (expr[i]==')')
            {
                if (top==-1)
                {
                    flag=1;
                    break;
                }
                else
                {
                    pop();
                }
            }
        }
    }
    if (seek()=='0' && flag==0)
    {
        printf("Valid expression\n");
    }
    else
    {
        printf("Invalid expression\n");
    }
    return 0;   
}

/*
Enter expression: ((a+b)*(c-d))
Valid expression
Enter expression: (()))
Invalid expression
*/