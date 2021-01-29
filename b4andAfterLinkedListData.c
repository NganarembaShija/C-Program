#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*start;

struct node *createList(int);
struct node *display(int);
struct node* insertBefore(int);
struct node* insertAfter(int);

int main(){
    start=(struct node*)malloc(sizeof(struct node));
    int size, choice;
    printf("Enter the number of nodes: ");
    scanf("%d",&size);
    createList(size);
    printf("\nMENU\n1. Insert Before a Data\n2. Insert After a Data\n\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: insertBefore(size);
                break;
        case 2: insertAfter(size);
                break;
                
        default: printf("Invalid Choice");
    }
    display(size);
}

struct node* createList(int size){
    struct node* traverse, *newNode;
    int i;
    printf("Enter Node 1 Data: ");
    scanf("%d",&start->data);
    start->link=NULL;
    traverse=start;
    for(i=2;i<=size;i++){
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Node %d data: ",i);
        scanf("%d",&newNode->data);
        newNode->link=NULL;
        traverse->link=newNode;
        traverse=traverse->link;
    }
}

struct node* display(int size){
    struct node* traverse;
    int i=0;
    traverse=start;
    printf("\n\nDisplaying\n");
    while(traverse!=NULL){
        printf("Node %d : %d\n",++i, traverse->data);
        traverse=traverse->link;
    }
}

struct node* insertBefore(int size)
{
    struct node* traverse, *nodebefore, *newNode;
    int data;
    traverse=start;
    nodebefore=traverse;
    printf("Search Data to insert Before: ");
    scanf("%d",&data);
    if(start->data==data){
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Insert new Node data: ");
        scanf("%d",&newNode->data);
        newNode->link=start;
        start=newNode;
    }
    else{
            while(data!=traverse->data){
                nodebefore=traverse;
                traverse=traverse->link;
            }
            newNode=(struct node*)malloc(sizeof(struct node));
            printf("Insert new Node data: ");
            scanf("%d",&newNode->data);
            newNode->link=nodebefore->link;
            nodebefore->link=newNode;
    }
    
}
struct node* insertAfter(int size)
{
    struct node* traverse, *nodecopy, *newNode;
    int data;
    traverse=start;
    nodecopy=traverse;
    printf("Search Data to insert After: ");
    scanf("%d",&data);
            while(data!=traverse->data){
                traverse=traverse->link;
                nodecopy=traverse->link;
            }
            newNode=(struct node*)malloc(sizeof(struct node));
            printf("Insert new Node data: ");
            scanf("%d",&newNode->data);
            newNode->link=nodecopy;
            if(start->data==data){
                start=newNode;
            }
            else{
                traverse->link=newNode;
            }
}

