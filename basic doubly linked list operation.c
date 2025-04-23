#include<stdio.h>
#include<stdlib.h>

struct DoubleLinkedList
{
    int val;
    struct DoubleLinkedList* next;
    struct DoubleLinkedList* prev;
};

static int count=0;
typedef struct DoubleLinkedList* dll;

dll create_node(int val)
{
	dll tmp = (struct DoubleLinkedList*)malloc(sizeof(struct DoubleLinkedList));
	tmp->val = val;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}

void insert_begin(dll head)
{
	int val;
	printf("Enter a number: ");
	scanf("%d",&val);
	dll tmp = create_node(val);
	tmp->next=head->next;
	if(head->next!=NULL)
    {
        tmp->next->prev=tmp;
    }
	tmp->prev=head;
	head->next=tmp;
	count++;
}

void insert_end(dll head)
{
	int val;
	printf("Enter a number: ");
	scanf("%d",&val);
	dll i=head;
	dll tmp = create_node(val);
	while(i->next!=NULL)
	{
		i=i->next;
	}
	tmp->val=val;
	i->next=tmp;
	tmp->prev=i;
	count++;
}

void insert_after_node(dll head)
{
	dll i=head;
	int pos, j=1;
	if (pos>count && pos<0)
	{
		printf("Position exceeds.\n");
	}
	else if (count==0)
	{
		insert_begin(head);
	}
	else
	{
		printf("Enter the number after which you want to insert[%d nodes]: ",count);
		scanf("%d",&pos);
		if(pos==0)
		{
			insert_begin(head);
		}
		else
		{
			while(i!=NULL)
			{
				if(j==pos+1)
				{
					int val;
					printf("Enter a number: ");
					scanf("%d",&val);
					dll tmp = create_node(val);
					tmp->next=i->next;
                    if(i->next!=NULL)
                    {
                        tmp->next->prev=tmp;
                    }
					tmp->prev=i;
					i->next=tmp;
					count++;
					break;
				}
				i=i->next;
				j++;
			}
		}
	}
}

void delete_begin(dll head)
{
	if(count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
	    if(head->next->next!=NULL)
        {
            head->next->next->prev=head;
        }
		head->next=head->next->next;
		count--;
	}
}

void delete_end(dll head)
{
	if(count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
		while(head->next->next!=NULL)
		{
			head=head->next;
		}
		head->next->prev=NULL;
		head->next=NULL;
		count--;
	}
}

void delete_after_node(dll head)
{
	dll i=head;
	int pos, j=1;
	if (count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
		printf("Enter the number after which you want to delete[%d nodes]: ",count-1);
		scanf("%d",&pos);
		if (pos>count || pos<0)
		{
			printf("Position exceed.\n");
		}
		else if(pos==0)
		{
			delete_begin(head);
		}
		else
		{
			while(i!=NULL)
			{
				if(j==pos+1)
				{
					if (i->next->next==NULL)
					{
						delete_end(head);
						break;
					}
					i->next=i->next->next;
					i->next->prev=i;
					count--;
					break;
				}
				i=i->next;
				j++;
			}
		}
	}
}

void display(dll head)
{
    dll i = head->next;
    dll j = head->prev;
    while(i!=NULL)
    {
        if(i->next==NULL)
        {
            j=i;
        }
        printf("%d->",i->val);
        i=i->next;
    }
    printf("NULL\nNULL");
    while(j!=head && j!=NULL)
    {
        printf("->%d",j->val);
        j=j->prev;
    }
    printf("\n");
}

int main()
{
	dll head = create_node(-1);
	printf("\n----------------MENU------------\n");
	printf("1. Insert at the beginning.\n");
	printf("2. Insert at the end.\n");
	printf("3. Insert After a Particular Node.\n");
	printf("4. Delete First Node.\n");
	printf("5. Delete Last Node.\n");
	printf("6. Delete After a Particular Node.\n");
	printf("7. Display the List.\n");
	printf("8. Exit.\n");
	printf("----------------------------------------------------------------\n");
	int ch;
	while(1)
	{
		printf("Enter Your Choice: ");
		scanf("%d",&ch);
		if (ch==8)
		{
			printf("Program exited.\n");
			break;
		}
		switch(ch)
		{
			case 1: insert_begin(head); break;
			case 2: insert_end(head); break;
			case 3: insert_after_node(head); break;
			case 4: delete_begin(head); break;
			case 5: delete_end(head); break;
			case 6: delete_after_node(head); break;
			case 7: display(head); break;
			default: printf("Invalid Choice.\n");
		}
	}

}


/*
----------------MENU------------
1. Insert at the beginning.
2. Insert at the end.
3. Insert After a Particular Node.
4. Delete First Node.
5. Delete Last Node.
6. Delete After a Particular Node.
7. Display the List.
8. Exit.
----------------------------------------------------------------
Enter Your Choice: 1
Enter a number: 10
Enter Your Choice: 1
Enter a number: 20
Enter Your Choice: 2
Enter a number: 30
Enter Your Choice: 7
20->10->30->NULL
NULL->30->10->20
Enter Your Choice: 3
Enter the number after which you want to insert[3 nodes]: 2
Enter a number: 40
Enter Your Choice: 7
20->10->40->30->NULL
NULL->30->40->10->20
Enter Your Choice: 4
Enter Your Choice: 7
10->40->30->NULL
NULL->30->40->10
Enter Your Choice: 5
Enter Your Choice: 7
10->40->NULL
NULL->40->10
Enter Your Choice: 6
Enter the number after which you want to delete[1 nodes]: 1
Enter Your Choice: 7
10->NULL
NULL->10
Enter Your Choice: 8
Program exited.
*/
