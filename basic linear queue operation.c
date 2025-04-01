#include <stdio.h>

int high=0,low=0,size=4,count=0;
int queue[0];

void enqueue()
{
    if (count==size)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        int n;
        printf("Enter a number: ");
        scanf("%d",&n);
        queue[high++]=n;
        printf("%d is inserted.\n",queue[high-1]);
        count++;
    }
}

void dequeue()
{
    if (count==0)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        printf("%d is deleted.\n",queue[low++]);
        count--;
    }
}

void display()
{
    if (count==0)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        for(int i=low;i<high;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main(){
	int choice;
	printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit");
	while(1){
		printf("\nEnter the choice:");
		scanf("%d",&choice);
		if(choice==4){
			printf("\n Exiting the program.");
			break;
		}
		switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("\n Wrong choice");
		}
	}
	return 0;
}

/*

1. Insert 
2. Delete 
3. Display 
4. Exit
Enter the choice:1
Enter a number: 10
10 is inserted.

Enter the choice:1
Enter a number: 20
20 is inserted.

Enter the choice:1
Enter a number: 30
30 is inserted.

Enter the choice:1
Enter a number: 40
40 is inserted.

Enter the choice:1
Queue Overflow.

Enter the choice:3
10 20 30 40 

Enter the choice:2
10 is deleted.

Enter the choice:2
20 is deleted.

Enter the choice:2
30 is deleted.

Enter the choice:2
40 is deleted.

Enter the choice:2
Queue Underflow.

Enter the choice:3
Queue Underflow.

*/
