#include <stdio.h>

int top=-1, size=4;
int stack[0];

void push() {
    int n;
    if (top==size-1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d",&n);
        stack[++top]=n;
    }
}

void pop() {
    if (top==-1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else {
        stack[--top];
    }
}

void seek() {
    if (top==-1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        printf("%d is at top of stack.\n",stack[top]);
    }
}

void display() {
    if (top==-1) 
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int choice;
    printf("List Operations: -\n");
    printf("1. Insert data onto stack.\n");
    printf("2. Remove data from stack.\n");
    printf("3. Display top element of stack.\n");
    printf("4. Display all elements of stack.\n");
    printf("5. Exit list operations.\n");
    while(1)
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        if (choice==5)
        {
            printf("Operation exited.\n");
            break;
        }
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                seek();
                break;
            case 4:
                display();
                break;
            default:
                printf("WRONG CHOICE!\n");
        }
    }
    return 0;
}