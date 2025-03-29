#include<stdio.h>

int low=50, high=50, size=5,count=0;
int queue[0];

void enqueue_front()
{
    if (count==size)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        int n;
		printf("Enter a number: ");
		scanf("%d",&n);
		queue[low-1]=n;
		printf("%d is inserted\n",queue[low-1]);
		low--; count++;
    }
}
void enqueue_back()
{
	if (count==size)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		int n;
		printf("Enter a number: ");
		scanf("%d",&n);
		queue[high]=n;
		printf("%d is inserted\n",queue[high]);
		high++; count++;
	}
}
void dequeue_front()
{
	if(count==0)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		printf("%d is deleted\n",queue[low]);
		low++;
		count--;
	}
}
void dequeue_back()
{
	if(count==0)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		high--;
		printf("%d is deleted\n",queue[high]);
		count--;
	}
}
void display()
{
	for(int i=low; i<high; i++)
	{
		printf("%d ",queue[i]); 
	}
	printf("\n");
}

int main(){
	int choice;
	printf("\n1. Insert from front \n2. Insert from back \n3. Delete from front \n4. Delete from back \n5. Display \n6. Exit");
	while(1){
		printf("\nEnter the choice:");
		scanf("%d",&choice);
		if(choice==6){
			printf("\nExiting the program.");
			break;
		}
		switch(choice){
			case 1:
				enqueue_front();
				break;
			case 2:
				enqueue_back();
				break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_back();
                break;
			case 5:
				display();
				break;
			default:
				printf("\n Wrong choice");
		}
	}
	return 0;
}