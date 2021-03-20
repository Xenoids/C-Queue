#include <stdio.h> // buat semua library
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) //insert
{
	if(front == -1 && rear == -1) // rear -> enqueue , front => dequeue
	{
		front = rear = 0;
		queue[rear] = x;
	}
	else if(((rear+1)%N )== front) // cek full apa kaga
	{
		printf("queue full!");
	}
	else
	{
		rear = (rear+1) % N;
		queue[rear] = x;
	}
}

void dequeue() // hapus
{
	if(front == -1 && rear == -1) printf("queue is empty!");
	else if(front == rear)
	{
		printf("\ndequeued element %d",queue[front]);
		front = rear = -1;
	}	
	else{
		printf("\ndequeued element %d",queue[front]);
		front = (front+1) % N;	
	}
	printf("\n");
}

void display()
{
	int i = front;
	if(front == -1 && rear == -1) printf("No data!");
	else
	{
		printf("Queue is : ");
		do
		{
			printf("%d ",queue[i]);
			i = (i+1) % N;
		}while(i !=rear);
		printf("%d ",queue[rear]);
	}
	printf("\n");
}

void peek()
{
	if(front == -1 && rear == -1) printf("No data!");
	else
	{
		printf("\nfront : %d",queue[front]);
	}
	printf("\n");
}
int main()
{
	enqueue(2);
	enqueue(-1);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	display();
	dequeue();
	dequeue();
	display();
	peek();
	enqueue(1);
	enqueue(9);
	display();
	dequeue();
	display();
//	enqueue(2);
//	display();
	return 0;
}

