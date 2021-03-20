#include <stdio.h> // buat semua library
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
	if(rear == N-1) printf("Overflow");
	else if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = x;
	}
	else
	{
		rear++;
		queue[rear] = x;
	}
}

void dequeue()
{
	if(front == -1 && rear == -1) printf("No data!");
	else if(front == rear) front = rear = -1;
	else
	{
		printf("\ndequeued element %d",queue[front]);
		front++;
	} 
	printf("\n");
}

void display()
{
	if(front == -1 && rear == -1) printf("No data!");
	else
	{
		for(int i=front;i<rear+1;i++)
		{
			printf("%d ",queue[i]);
		}
	}
	printf("\n");
}

void peek()
{
	if(front == -1 && rear == -1) printf("No Data!");
	else
	{
		printf("\nfront queue : %d",queue[front]);
	}
	printf("\n");
}



int main()
{
	enqueue(2);
	enqueue(5);
	enqueue(-1);
	enqueue(4);
	display();
	dequeue();
	display();
	peek();
	dequeue();
	peek();
	display();
	enqueue(2);
	display();
	return 0;
}

