#include <stdio.h>

int high=-1,low=-1,size=4;
int queue[1];

void enqueue()
{
    if (high==size-1 && low==size-1)
    {
        low=-1; high=-1;
        int n;
        printf("Enter a number: ");
        scanf("%d",&n);
        queue[++high]=n;
        printf("%d is inserted.\n",queue[high]);
    }
    else if (high==size-1)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        int n;
        printf("Enter a number: ");
        scanf("%d",&n);
        queue[++high]=n;
        printf("%d is inserted.\n",queue[high]);
    }
}

void dequeue()
{
    if (low==high)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        low++;
        printf("%d is deleted.\n",queue[low]);
    }
}

void display()
{
    if (low==high)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        for(int i=(low==-1)?0:low;i<=high;i++)
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
