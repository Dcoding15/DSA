#include<stdio.h>
#include<stdlib.h>

struct SingleLinkedList
{ 
    int val;
    struct SingleLinkedList* next;
};

static int count=0;

typedef struct SingleLinkedList* sll;

sll create_node(int val)
{
	sll tmp = (struct SingleLinkedList*)malloc(sizeof(struct SingleLinkedList));
	tmp->val = val;
	tmp->next = NULL;
	return tmp;
}

void insert_begin(sll head)
{
	int val;
	printf("Enter a number: ");
	scanf("%d",&val);
	sll tmp = create_node(val);
	tmp->next=head->next;
	head->next=tmp;
	count++;
}

void insert_end(sll head)
{
	int val;
	printf("Enter a number: ");
	scanf("%d",&val);
	sll i=head;
	sll tmp = create_node(val);
	while(i->next!=NULL)
	{
		i=i->next;
	}
	tmp->val=val;
	i->next=tmp;
	count++;
}

void insert_after_node(sll head)
{
	sll i=head;
	int val, pos, j=1;
	printf("Enter a number: ");
	scanf("%d",&val);
	sll tmp=create_node(val);
	if (count==0)
	{
		tmp->next=head->next;
		head->next=tmp;
		count++;
	}
	else
	{
		printf("Enter the number after which you want to insert[%d nodes]: ",count);
		scanf("%d",&pos);
		if (pos>count+1)
		{
			printf("Position exceed.\n");
		}
		else if(pos<1)
		{
			printf("Position exceed.\n");
		}
		else
		{
			while(i!=NULL)
			{
				if(j==pos+1)
				{
					tmp->next=i->next;
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

void insert_before_node(sll head)
{
	sll i=head;
	int val, pos, j=1;
	printf("Enter a number: ");
	scanf("%d",&val);
	sll tmp=create_node(val);
	if (count==0)
	{
		tmp->next=head->next;
		head->next=tmp;
		count++;
	}
	else
	{
		printf("Enter the number after which you want to insert[%d nodes]: ",count);
		scanf("%d",&pos);
		if (pos>count)
		{
			printf("Position exceed.\n");
		}
		else if(pos<1)
		{
			printf("Position exceed.\n");
		}
		else
		{
			while(i!=NULL)
			{
				if(j==pos)
				{
					tmp->next=i->next;
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

void insert_between_two_particular_node(sll head)
{
	sll i=head;
	int node1, node2, flag=1;
	int val;
	printf("Enter the first node number: ");
	scanf("%d",&node1);
	printf("Enter the second node number: ");
	scanf("%d",&node2);
	printf("Enter the number to be inserted: ");
	scanf("%d",&val);
	sll tmp=create_node(val);
	if (count<2)
	{
		printf("List has less than two nodes!\n");
	}
	else
	{
		while(i->next!=NULL)
		{
			i=i->next;
			if (i->val==node1 && i->next->val==node2)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("%d and %d two corresponding values are not found.\n",node1,node2);
		}
		else
		{
			tmp->next=i->next;
			i->next=tmp;
			count++;
		}
	}
}

void insert_at_middle_of_list(sll head)
{
	int mid;
	sll i=head;
	if(count%2==0)
	{
		mid=count/2;
	}
	else
	{       
		mid=(count+1)/2;
	}
	int val;
	printf("Enter the number to be inserted at middle of list: ");
	scanf("%d",&val);
	sll tmp = create_node(val);
	for(int j=1; j!=mid+1; j++)
	{
		i=i->next;
	}
	tmp->next=i->next;
	i->next=tmp;
	count++;
}

void delete_begin(sll head)
{
	if(count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
		head->next=head->next->next;
		count--;
	}
}

void delete_end(sll head)
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
		head->next=head->next->next;
		count--;
	}
}

void delete_after_node(sll head)
{
	sll i=head;
	int val, pos, j=1;
	if (count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
		printf("Enter the number after which you want to delete[%d nodes]: ",count-1);
		scanf("%d",&pos);
		if (pos>count)
		{
			printf("Position exceed.\n");
		}
		else if(pos<1)
		{
			printf("Position exceed.\n");
		}
		else
		{
			while(i!=NULL)
			{
				if(j==pos+1)
				{
					i->next=i->next->next;
					count--;
					break;
				}
				i=i->next;
				j++;
			}
		}
	}
}

void delete_before_node(sll head)
{
	sll i=head;
	int val, pos, j=1;
	if (count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
		printf("Enter the number after which you want to insert[%d nodes]: ",count);
		scanf("%d",&pos);
		if (pos>count)
		{
			printf("Position exceed.\n");
		}
		else if(pos<1)
		{
			printf("Position exceed.\n");
		}
		else
		{
			while(i!=NULL)
			{
				if(j==pos-1)
				{
					i->next=i->next->next;
					count--;
					break;
				}
				i=i->next;
				j++;
			}
		}
	}
}

void delete_kth_node(sll head)
{
	sll i=head;
	int val, pos, j=1;
	if (count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
		printf("Enter the number at which you want to insert[%d nodes]: ",count);
		scanf("%d",&pos);
		if (pos>count)
		{
			printf("Position exceed.\n");
		}
		else if(pos<1)
		{
			printf("Position exceed.\n");
		}
		else
		{
			while(i!=NULL)
			{
				if(j==pos)
				{
					i->next=i->next->next;
					count--;
					break;
				}
				i=i->next;
				j++;
			}
		}
	}
}

void delete_any_node(sll head)
{
	sll i=head;
	int val, pos;
	if (count==0)
	{
		printf("List is empty.\n");
	}
	else
	{
		printf("Enter the number at which you want to insert: ");
		scanf("%d",&pos);
		while(i!=NULL)
		{
			if(i->next->val==pos)
			{
				i->next=i->next->next;
				count--;
				break;
			}
			i=i->next;
		}
	}
}

void display(sll head)
{
    sll i = head->next;
    while(i!=NULL)
    {
        printf("%d ",i->val);
        i=i->next;
    }
    printf("\n");
}

void display_reverse(sll i)
{
	if (i==NULL)
	{
		return;
	}
	else
	{
		display_reverse(i->next);
		printf("%d ",i->val);
	}
}

void physically_reverse_list(sll head)
{
	sll prev = NULL;
	sll curr = head->next;
	sll next = NULL;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head->next = prev;
}

void display_min_max(sll head)
{
	if(count==0)
	{
		printf("List is empty\n");
	}
	else
	{
		int min=head->next->val, max=head->next->val;
		sll i = head->next;
		while(i!=NULL)
		{
			if(i->val<min)
			{
				min=i->val;
			}
			if(i->val>max)
			{
				max=i->val;
			}
			i=i->next;
		}
		printf("Minimum value is %d and maximum value is %d.\n",min,max);
	}
}

int main()
{
	sll head = create_node(-1);
	printf("\n----------------MENU------------\n");
	printf("1. Insert at the begining.\n");
	printf("2. Insert at the end.\n");
	printf("3. Insert After a Particular Node.\n");
	printf("4. Insert Before a Particular Node.\n");
	printf("5. Insert Between two Particular Node.\n");
	printf("6. Insert at the Middle of the List.\n");
	printf("7. Delete First Node.\n");
	printf("8. Delete Last Node.\n");
	printf("9. Delete After a Particular Node.\n");
	printf("10. Delete Before a Particular Node.\n");
	printf("11. Delete K-th Node.\n");
	printf("12. Delete any Node.\n");
	printf("13. Display the List.\n");
	printf("14. Display the List in Reverse Order.\n");
	printf("15. Physically Reverse the List.\n");
	printf("16. Finding the Largest and Smallest Element from the List.\n");
	printf("17. Exit.\n");
	printf("----------------------------------------------------------------\n");
	int ch,x;
	while(1)
	{
		printf("Enter Your Choice: ");
		scanf("%d",&ch);
		if (ch==17)
		{
			printf("Program exited.\n");
			break;
		}
		switch(ch)
		{
			case 1: insert_begin(head); break;
			case 2: insert_end(head); break;
			case 3: insert_after_node(head); break;
			case 4: insert_before_node(head); break;
			case 5: insert_between_two_particular_node(head); break;
			case 6: insert_at_middle_of_list(head); break;
			case 7: delete_begin(head); break;
			case 8: delete_end(head); break;
			case 9: delete_after_node(head); break;
			case 10: delete_before_node(head); break;
			case 11: delete_kth_node(head); break;
			case 12: delete_any_node(head); break;
			case 13: display(head); break;
			case 14: display_reverse(head->next); printf("\n"); break;
			case 15: physically_reverse_list(head); break;
			case 16: display_min_max(head); break;
			default: printf("Invalid Choice.\n");
		}
	}
	
}


/*

Output: -
----------------MENU------------
1. Insert at the begining.
2. Insert at the end.
3. Insert After a Particular Node.
4. Delete at the beginning.
5. Delete at the end.
6. Delete After a Particular Node.
7. Display the List.
8. Exit.
--------------------------------
Enter Your Choice: 1
Enter a number: 10
Enter Your Choice: 1
Enter a number: 20
Enter Your Choice: 2
Enter a number: 30
Enter Your Choice: 3
Enter a number: 40
Enter the number after which you want to insert[3 nodes]: 2
Enter Your Choice: 7
20 10 40 30 
Enter Your Choice: 4
Enter Your Choice: 7
10 40 30 
Enter Your Choice: 5
Enter Your Choice: 7
10 40 
Enter Your Choice: 6
Enter the number after which you want to delete[1 nodes]: 1
Enter Your Choice: 7
10
Enter Your Choice: 8
Program exited.
*/
