#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
    struct node* prev;
};

int count=0;

struct node* create_node(int n)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val=n;
    tmp->next=NULL;
    tmp->prev=NULL;
    return tmp;
}

void make_link(struct node* a, struct node* b, struct node* c)
{
    b->prev=a;
    b->next=c;
    a->next=b;
    c->prev=b;
}

void insert_at_begin(struct node* a, struct node* b)
{
    int n;
    printf("Enter the value: ");
    scanf("%d",&n);
    struct node* tmp = create_node(n);
    if (a->next==b)
    {
        make_link(a,tmp,b);
    }
    else
    {
        make_link(a,tmp,a->next);
    }
    count++;
}

void insert_at_mid(struct node* a,struct node*  b)
{
    int n, position;
    printf("Enter the value: ");
    scanf("%d",&n);
    struct node* tmp = create_node(n);
    if (a->next==b)
    {
        make_link(a,tmp,b);
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
                    make_link(a->next->prev,tmp,a->next);
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

void insert_at_end(struct node* a, struct node*  b)
{
    int n;
    printf("Enter the value: ");
    scanf("%d",&n);
    struct node* tmp = create_node(n);
    while(a->next!=b)
    {
        a=a->next;
    }
    make_link(a,tmp,b);
    count++;
}

void delete_at_begin(struct node* a, struct node* b)
{
    if(a->next==b)
    {
        printf("Empty list\n");
    }
    else
    {
        a->next=a->next->next;
        a->next->prev=a;
        count--;
    }
}

void delete_at_mid(struct node* a, struct node* b)
{
    int position;
    if (a->next==b)
    {
        printf("Empty list\n");
        count--;
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
                if (i++==position-1 && a!=b)
                {
                    a->next=a->next->next;
                    a->next->prev=a;
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

void delete_at_end(struct node* a,struct node* b)
{
    if (b->prev==a)
    {
        printf("Empty list\n");
    }
    else
    {
        b->prev=b->prev->prev;
        b->prev->next=b;
        count--;
    }
}

void display(struct node* a,struct node* b)
{
    a=a->next;
    while(a->next!=NULL)
    {
        printf("%d->",a->val);
        a=a->next;
    }
    printf("NULL\n");
    b=b->prev;
    printf("NULL");
    while(b->prev!=NULL)
    {
        printf("<-%d",b->val);
        b=b->prev;
    }
    printf("\n");
}

int main()
{
    int choice;
    struct node* head = create_node(-1);
    struct node* tail = create_node(-1);
    head->next=tail;
    tail->prev=head;
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
                insert_at_begin(head,tail);
                break;
            case 2:
                insert_at_mid(head,tail);
                break;
            case 3:
                insert_at_end(head,tail);
                break;
            case 4:
                delete_at_begin(head,tail);
                break;
            case 5:
                delete_at_mid(head,tail);
                break;
            case 6:
                delete_at_end(head,tail);
                break;
            case 7:
                display(head,tail);
                break;
            default:
                printf("WRONG CHOICE!\n");
        }
    }
    return 0;
}