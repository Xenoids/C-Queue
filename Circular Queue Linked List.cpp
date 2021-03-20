#include <stdio.h> // buat semua library
#include <stdlib.h>

struct node{
	int data;
	node* link;
}*front,*rear;

node* createnode(int data)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->link =NULL;
}

void enqueue(int data){
	if(rear == NULL) 
	{
	node* newnode = createnode(data);
	front = rear = newnode; // no data
	rear->link = front;
	}
	
	else{
		node* newnode = createnode(data);
		rear->link = newnode;
		rear = newnode;
		rear->link = front;
	}
}

void dequeue()
{
	if(front == NULL && rear == NULL) printf("No data!");
	else if(front == rear)
	{
		printf("dequeue data %d ",front->data);
		node* temp;
		temp = front;
		front = rear = NULL;
		free(temp);
	}
	else{
	printf("dequeue data %d",front->data);
	node* temp;
	temp = front;
	front = front->link;
	rear->link = front;
	free(temp);
	}
	printf("\n");
}

void display()
{
	if(front == NULL && rear == NULL) printf("No data!");
	else{
		node* temp;
		temp = front;
		printf("queue list : ");
		while(temp->link != front)
		{
		printf("%d ",temp->data);
		temp = temp->link;
		}
		printf("%d",temp->data);
	}
	printf("\n");
}

void peek()
{
	if(front == NULL && rear == NULL) printf("No Data!");
	else
	{
		printf("front : %d ",front->data);
	}
	printf("\n");
}

int main()
{
	enqueue(2);
	enqueue(-1);
	enqueue(5);
	display();
	dequeue();
	dequeue();
	display();
	enqueue(10);
	enqueue(1);
	display();
	peek();
	return 0;
}

