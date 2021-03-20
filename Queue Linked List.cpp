#include <stdio.h> // buat semua library
#include <stdlib.h>

struct node{
	int data;
	node* link;
}*front,*rear;

node* createnode(int data){
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;
}

void enqueue(int data){
	if(front == 0 && rear == 0) {
		node* newnode = createnode(data);
		front = rear = newnode;
	}
	else{
	node* newnode = createnode(data);
	rear->link = newnode;
	rear = newnode;
	}
}

void dequeue()
{
	
	if(front == 0 && rear == 0) printf("No data!");
	else{
		node* temp;
		temp = front;
		printf("\ndequeued data : %d",front->data);
		front = front->link;
		free(temp);
	}
	printf("\n");
}

void display()
{
	node* temp;
	if(front == 0 && rear == 0) printf("No data!");
	else{
		temp = front;
		printf("all queue :");
	while(temp != NULL){
		printf(" %d ",temp->data);
		temp = temp->link;
		}
	}
	printf("\n");
}

void peek()
{
	if(front == 0 && rear == 0) printf("No data!");
	else
	{
		printf("front data : %d\n",front->data);
	}
}


int main()
{
	enqueue(5);
	enqueue(1);
	enqueue(-3);
	display();
	dequeue();
	dequeue();
	peek();
	display();
	enqueue(10);
	enqueue(2);
	dequeue();
	display();
	return 0;
}

