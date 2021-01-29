#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*start;

struct node *createList(int);
struct node *display(int);
struct node* insert(int);

int main(){
    start=(struct node*)malloc(sizeof(struct node));
    int size;
    printf("Enter the number of nodes: ");
    scanf("%d",&size);
    createList(size);
    insert(size);
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

struct node* insert(int size){
    int i,position, item, count=1;
    struct node* traverse, *newNode, *prev;
    traverse=start;
    prev=traverse;
    printf("Enter the position to insert: ");
    scanf("%d",&position);
    if(position>size+1){
        printf("Enter a valid position");
         return start;
    }
    printf("Enter the item to insert: ");
    scanf("%d",&item);
    // Creating node and inserting data 
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    if(position==1) // When location is at starting position
    {
        newNode->link=start;
        start=newNode;
    }
    else// When location is at other position
    {
        while(count!=position)
        {
            prev=traverse;
            traverse=traverse->link;
            ++count;
        }
        newNode->link=prev->link;
        prev->link=newNode;
    }
    
}
