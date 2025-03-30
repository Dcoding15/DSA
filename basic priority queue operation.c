#include <stdio.h>

int high=-1,low=-1,size=4;
int queue[1];

int max()
{
    int indx=(low==-1)?0:low;
    int max=queue[indx];
    for(int i=indx; i<=high; i++)
    {
        if (max<=queue[i])
        {
            max=queue[i];
            indx=i;
        }
    }
    return indx;
}

int min()
{
    int indx=(low==-1)?0:low;
    int min=queue[indx];
    for(int i=indx; i<=high; i++)
    {
        if (min>=queue[i])
        {
            min=queue[i];
            indx=i;
        }
    }
    return indx;
}

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

void dequeue_ascending_order()
{
    if (low==high)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        printf("%d is deleted.\n",queue[min()]);
        for(int i=min(); i<high; i++)
        {
            queue[i]=queue[i+1];
        }
        high--;
    }
}

void dequeue_descending_order()
{
    if (low==high)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        printf("%d is deleted.\n",queue[max()]);
        for(int i=max(); i<high; i++)
        {
            queue[i]=queue[i+1];
        }
        high--;
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
	printf("\n1. Insert \n2. Delete in ascending order \n3. Delete in descending order \n4. Display \n5. Exit");
	while(1){
		printf("\nEnter the choice:");
		scanf("%d",&choice);
		if(choice==5){
			printf("\n Exiting the program.");
			break;
		}
		switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue_ascending_order();
				break;
            case 3:
                dequeue_descending_order();
                break;
			case 4:
				display();
				break;
			default:
				printf("\n Wrong choice");
		}
	}
	return 0;
}