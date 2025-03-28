#include<stdio.h>

int size=0;
int list[0];

void insert_at_begin()
{
    int n;
    printf("Enter the value: ");
    scanf("%d",&n);
    size++;
    if (size==0)
    {
        list[size-1]=n;
    }
    else
    {
        for (int i=size-1; i>=0; i--)
        {
            list[i]=list[i-1];
        }
        list[0]=n;
    }
}

void insert_at_mid()
{
    int n, position;
    printf("Enter the value: ");
    scanf("%d",&n);
    size++;
    if (size==0)
    {
        list[size-1]=n;
    }
    else
    {
        printf("Enter the position [%d-%d]: ",1,size);
        scanf("%d",&position);
        if (position>size)
        {
            printf("Specified position is out of range.\n");
        }
        else
        {
            for (int i=size; i>=position; i--)
            {
                list[i]=list[i-1];
            }
            list[position-1]=n;
        }
    }
}

void insert_at_end()
{
    int n;
    printf("Enter the value: ");
    scanf("%d",&n);
    size++;
    list[size-1]=n;
}

void delete_at_begin()
{
    if (size==0)
    {
        printf("EMPTY LIST!\n");
    }
    else
    {
        for(int i=0; i<size-1; i++)
        {
            list[i]=list[i+1];
        }
        size--;
    }
}

void delete_at_mid()
{
    if (size==0)
    {
        printf("EMPTY LIST!\n");
    }
    else
    {
        int position;
        printf("Enter the position [%d-%d]: ",1,size);
        scanf("%d",&position);
        if (position>size)
        {
            printf("Specified position is out of range.\n");
        }
        else
        {
            for (int i=position-1; i<size-1; i++)
            {
                list[i]=list[i+1];
            }
            size--;
        }
    }
}

void delete_at_end()
{
    if (size==0)
    {
        printf("EMPTY LIST!\n");
    }
    else
    {
        size--;
    }
}

void display()
{
    if (size==0)
    {
        printf("EMPTY LIST!\n");
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            printf("%d ",list[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("List Operations: -\n");
    printf("1. Insert data at beginning position of list.\n");
    printf("2. Insert data at spcified position of list.\n");
    printf("3. Insert data at ending position of list.\n");
    printf("4. Remove data at beginning position of list.\n");
    printf("5. Remove data at spcified position of list.\n");
    printf("6. Remove data at ending position of list.\n");
    printf("7. Display data of list.\n");
    printf("8. Exit list operations.\n");
    while(1)
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        if (choice==8)
        {
            printf("Operation exited.\n");
            break;
        }
        switch (choice)
        {
            case 1:
                insert_at_begin();
                break;
            case 2:
                insert_at_mid();
                break;
            case 3:
                insert_at_end();
                break;
            case 4:
                delete_at_begin();
                break;
            case 5:
                delete_at_mid();
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                display();
                break;
            default:
                printf("WRONG CHOICE!\n");
        }
    }
    return 0;
}