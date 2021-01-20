#include<stdio.h>
#include<stdlib.h>
struct node
{
		int data;
		struct node *link;
}*start;
void createList(int);
void display(int);
void delete();
int main()
{
	int size;
	printf("Enter the size of the nodes: ");
	scanf("%d",&size);
	createList(size);
	delete();
	display(size);
}

void createList(int size)
{
	struct node *p, *createNode;
	int i;
	start=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("Memory not allocated");
	}
	p=start;
	printf("Enter Node 1 data: ");
	scanf("%d",&start->data);
	start->link=NULL;
	for(i=2;i<=size;i++)
	{
		createNode=(struct node*)malloc(sizeof(struct node));
		if(createNode==NULL)
		{
			printf("Memory Not Allocated");
		}
		else
		{
			printf("Enter Node %d data: ",i);
			scanf("%d",&createNode->data);
			createNode->link=NULL;
			p->link=createNode;
			p=p->link;
			
		}
	}
	
	
	
}
void display(int size)
{
	struct node *p;
	p=start;
	printf("\n\nThe Remaining Nodes are: \n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->link;
	}
}

void delete()
{
	int data;
	struct node *p,*prev;
	printf("\nEnter the data to delete: ");
	scanf("%d",&data);
	p=start;
	prev=p;
	while(p!=NULL)
	{
		if(p->data==data)
		{
			if(start->data==data)
			{
				start=start->link;
				p=start;
			}
			else
			{
				prev->link=p->link;
				p=p->link;
			}

		}
		else
		{	
			prev=p;
			p=p->link;
		}

	}


}
