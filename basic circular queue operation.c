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
        if(count<size && high>=size)
        {
            high=0;
            queue[high]=n;
        }
        else
        {
            queue[high]=n;
        }
        printf("%d is inserted.\n",queue[high++]);
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
        if(count<size && low>=size)
        {
            printf("%d is deleted.\n",queue[low]);
            low=0;
        }
        else
        {
            printf("%d is deleted.\n",queue[low++]);
        }
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
        int i=low;
        int j=1;
        while(j<=count)
        {
            printf("%d ",queue[i]);
            i++; j++;
            i=(i==size)?0:i;
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