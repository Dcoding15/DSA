#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

int count=0;

struct node* create_node(int n)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val=n;
    tmp->next=NULL;
    return tmp;
}

void insert_at_begin(struct node* a)
{
    int n;
    printf("Enter the value: ");
    scanf("%d",&n);
    struct node* tmp = create_node(n);
    tmp->next=a->next;
    a->next=tmp;
    count++;
}

void insert_at_mid(struct node* a)
{
    int n, position;
    printf("Enter the value: ");
    scanf("%d",&n);
    struct node* tmp = create_node(n);
    if (count==0)
    {
        tmp->next=a->next;
        a->next=tmp;
        count++;
    }
    else
    {
        printf("Enter the position [1-%d]: ",count+1);
        scanf("%d",&position);
        if (position>count+1)
        {
            printf("Linked list out of range.\n");
        }
        else
        {
            int i=0;
            while(1)
            {
                if (i++==position-1 && a!=NULL)
                {
                    tmp->next=a->next;
                    a->next=tmp;
                    count++;
                    break;
                }
                else
                {
                    a=a->next;
                }
            }
        }
    }
}

void insert_at_end(struct node* a)
{
    int n;
    printf("Enter the value: ");
    scanf("%d",&n);
    struct node* tmp = create_node(n);
    while(a->next!=NULL)
    {
        a=a->next;
    }
    tmp->next=a->next;
    a->next=tmp;
    count++;
}

void delete_at_begin(struct node* a)
{
    if (a->next==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        a->next=a->next->next;
        count--;
    }
}

void delete_at_mid(struct node* a)
{
    int position;
    if (a->next==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("Enter the position [1-%d]: ",count);
        scanf("%d",&position);
        if (position>count)
        {
            printf("Linked list out of range.\n");
        }
        else
        {
            int i=0;
            while(1)
            {
                if (i++==position-1)
                {
                    a->next=a->next->next;
                    count--;
                    break;
                }
                else
                {
                    a=a->next;
                }
            }
        }
    }
}

void delete_at_end(struct node* a)
{
    if (a->next==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while(a->next->next!=NULL)
        {
            a=a->next;
        }
        a->next=a->next->next;
        count--;
    }
}

void display(struct node* tmp)
{
    tmp=tmp->next;
    while(tmp!=NULL)
    {
        printf("%d->",tmp->val);
        tmp=tmp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    struct node* head = create_node(-1);
    printf("Linked List Operations: -\n");
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
                insert_at_begin(head);
                break;
            case 2:
                insert_at_mid(head);
                break;
            case 3:
                insert_at_end(head);
                break;
            case 4:
                delete_at_begin(head);
                break;
            case 5:
                delete_at_mid(head);
                break;
            case 6:
                delete_at_end(head);
                break;
            case 7:
                display(head);
                break;
            default:
                printf("WRONG CHOICE!\n");
        }
    }
    return 0;
}