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
