#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}*head;

struct node *createList(int);
struct node *display();
struct node *insertion();
struct node *insertBefore();
struct node *insertAfter();
struct node *delete();

int main()
{
	int size, choice;
	head= (struct node*)malloc(sizeof(struct node));
	while(1){
		printf("\n~~~~MAIN MENU~~~~\n1. Create List\n2. Insertion\n3. Deletion\n4. Display\n\nEnter choice: ");
		scanf("%d",&choice);
	
		switch(choice){
			case 1: printf("\nEnter the number of Nodes: \n");
					scanf("%d",&size);
					createList(size);
					break;
			case 2: insertion();
					break;

			case 3: delete();
					break;

			case 4: display();
					break;

			default: printf("Please enter a valid choice\n");
		}
	}
}


struct node *createList(int size){
	struct node *traverse, *newNode;
	int i;
	if(head==NULL){
		printf("Memory allocation failed\n");
		return head;
	}
	printf("\nEnter Node 1 data: ");
	scanf("%d",&head->data);
	head->link=NULL;
	traverse=head;
	for(i=2;i<=size;i++){
		newNode=(struct node*)malloc(sizeof(struct node));
		if(newNode==NULL){
			printf("New Node memory allocation failed\n");
			return head;
		}
		printf("Enter Node %d data: ",i);
		scanf("%d",&newNode->data);
		newNode->link=NULL;
		traverse->link=newNode;
		traverse=traverse->link;
	}

	system("clear");
	printf("\nList Created Successfully\n");

}

struct node *display(){
	int i=0;
	struct node *traverse;
	traverse=head;
	system("clear");
	printf("\nDisplaying\n");
	while(traverse!=NULL){
		printf("Node %d : %d\n",++i,traverse->data);
		traverse=traverse->link;
	}
}

struct node *insertion(){
	int choice;
	printf("\n1. Insert before a node\n2. Insert after a node\n\nEnter choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: insertBefore();
				break;

		case 2: insertAfter();
				break;
		default: printf("Select a valid input\n");

	}
	system("clear");
}

struct node *insertBefore(){
	struct node *traverse, *prev, *newNode;
	int data;
	traverse=head;
	prev=traverse;
	printf("Enter the data of the node to insert to node before: ");
	scanf("%d",&data);
	if(traverse->data==data){
		printf("Enter the data of the new node: ");
		scanf("%d",&data);
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=data;
		head=newNode;
		newNode->link=traverse;
		return head;
	}
	while(traverse->data!=data){
		prev=traverse;
		traverse=traverse->link;
	}
	printf("Enter the data of the new node: ");
	scanf("%d",&data);
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	prev->link=newNode;
	newNode->link=traverse;
	system("clear");
	printf("\nInsertion Successful\n");

}

struct node *insertAfter(){
	struct node *traverse, *newNode, *prev;
	int data;
	traverse=head;
	printf("Enter the data of the location: ");
	scanf("%d",&data);
	while(traverse!=NULL){
		if(traverse->data==data){
			prev=traverse;
			traverse=traverse->link;
			break;
		}
		else{
			traverse=traverse->link;
		}
	}
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of the new node: ");
	scanf("%d",&newNode->data);
	prev->link=newNode;
	newNode->link=traverse;
	system("clear");
	printf("\nInsertion Successful\n");
}

struct node *delete(){
	struct node *traverse, *prev;
	int data;
	traverse=head;
	printf("Enter the data to delete: ");
	scanf("%d",&data);
	while(traverse!=NULL){
		if(traverse->data==data){
			if(head->data==data){
				head=head->link;
				break;
			}
			else{
				prev->link=traverse->link;
				break;
			}
		}
		prev=traverse;
		traverse=traverse->link;
	}
	system("clear");
	printf("\nDeletion Successful\n");
}