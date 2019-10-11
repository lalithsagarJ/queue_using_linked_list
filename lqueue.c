#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
typedef struct node *NODE;
NODE front=NULL , rear=NULL;
int count=0;int size =10;
NODE getnode()
{	
	NODE x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nout of memory ");
		exit(0);
	}	
	else 
		return x;
}
void enqueue(int item)
{
	if(count==size)
		printf("\noverflow");
	else
	{
		NODE temp=getnode();
		temp->data=item;
		temp->link=NULL;
		if(count==0)
		{
			front=temp;
			rear=temp;
		}
		else
		{
			rear->link=temp;
			rear=temp;
		}
		count++;
	}
}
void dequeue()
{
	if(count==0)
		printf("\nunderflow");
	else
	{
		NODE temp=front;
		if(count==1)
		{
			front=rear=NULL;
		}
		else
			front=front->link;
		free(temp);
		count--;
	}
}
void isfull()
{
	if(count==size)
		printf("\nthe queue is full");
	else
		printf("\nthe queue is not full");
}
void isempty()
{
	if(front==NULL)
		printf("\nthe queue is empty");
	else
		printf("\nthe queue is not empty");
}
void display()
{
	if(front==NULL)
		printf("\nqueue is empty");
	else 
	{
		NODE ptr=front;
		printf("\nelements in queue are\n");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
	}
}
int main()
{
	int options,ele;
	do
	{
		printf("\n1.enqueue\n2.dequeue\n3.isfull\n4.isempty\n5.display\n0.exit\n");
		scanf("%d",&options);
		switch(options)
		{
			case 1:printf("\nenter the element to be queued :"); 
				scanf("%d",&ele);
				enqueue(ele);
				break;
			case 2:dequeue();
				break;
			case 3:isfull();
				break;
			case 4:isempty();
				break;
			case 5:display();
				break;
		}
	}while(options!=0);
	return 0;
}
