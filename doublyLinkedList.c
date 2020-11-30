#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=0;

void insertAtBeg(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    temp->prev = 0;
    if(head!=0){
    head->prev = temp;
    }
    head=temp;
}
void insertAtEnd(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)),*temp1=head;
    temp->data = data;
    temp->next = 0;
    if(head == 0){
        insertAtBeg(data);
        return;
    }
    while(temp1->next != 0){
        temp1 = temp1->next;
    }
    temp->prev = temp1;
    temp1->next = temp;
}
void insertAtPos(int n,int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)),*temp1=head;
    temp->data = data;
    temp->next = 0;
    if(n==0){
        printf("Give position greater than or equal to 1\n");
        return;
    }
    if(n==1 || head ==0){
        insertAtBeg(data);
        return;
    }
    int i=0;
    while(i<n-2 && temp1!=0){
        temp1 = temp1->next;
        i++;
    }
    if(temp1==0){
        printf("Invalid Pos\n");
        return;
    }
    temp1->next->prev=temp;
    temp->prev = temp1;
    temp->next = temp1->next;
    temp1->next = temp;
}


void printListForward(){
    struct Node *temp =head;
    while(temp!=0){
        printf("%d ", temp->data);
        temp =  temp->next;
    }
    printf("\n");
}
void printListReverse(){
    struct Node *temp =head;
    while(temp->next!=0){
        temp =  temp->next;
    }
    while(temp!=0){
       printf("%d ", temp->data);
        temp =temp->prev;
    }
    printf("\n");
}

void deleteAtBeg(){
    struct Node *temp = head;
    head=temp->next;
    if(head!=0){
        head->prev = 0;
    }
    free(temp);
}
void deleteAtEnd(){
    struct Node *temp =  head,*temp1;
    while(temp->next!=0){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next = 0;
    free(temp);
}
void deleteAtPos(int n){
    struct Node *temp =  head,*temp1;
    int i=0;
    if( n = 0){
       printf("Error: Invalid Pos\n");
       return;
    }
    while(i<n-2 && temp!=0){
        temp=temp->next;
        i++;
    }
   if(temp == 0){
       printf("Error: Invalid Pos\n");
    return;
   }
   temp1 = temp->next;
   temp->next = temp1->next;
   temp1->next->prev=temp;
   free(temp1);
}
int main(void) 
{
    insertAtEnd(2);
    insertAtEnd(4);
    insertAtEnd(6);
    insertAtEnd(8);
    insertAtPos(1,3);
    insertAtPos(5,5);
    insertAtPos(3,7);
    printListForward();
    printListReverse();
    deleteAtPos(5);
    printListForward();
	return 0;
}


