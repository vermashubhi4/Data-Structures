#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head=0;

void insertAtBeg(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
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
    while(i<n-2 && temp!=0){
        temp1 = temp1->next;
        i++;
    }
    if(temp1==0){
        printf("Invalid Pos\n");
        return;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void reverseListIteratively(struct Node* head){
    struct Node *current=head,*prev=0,*next;
    
    while(current!=0){
        next=current->next;
        current->next = prev;
        prev=current;
        current=next;
    }
    head=prev;
    // Print(head);
}

void reverseListRecursively(struct Node* p){
    
    if(p->next == 0){
        head = p;
        return;
    }
    reverseListRecursively(p->next);
    struct Node *q=p->next;
    q->next=p;
    p->next = 0;
    
}

void printForwardListRecursively(struct Node *p){
    if(p == 0){
        return;
    }
    printf("%d\n",p->data);
    printForwardListRecursively(p->next);
}

void printReverseListRecursively(struct Node *p){
    if(p==0){
        return;
    }
    printReverseListRecursively(p->next);
    printf("%d\n",p->data);
}

void printList(){
    struct Node *temp =head;
    while(temp!=0){
        printf("%d ", temp->data);
        temp =  temp->next;
    }
    printf("\n");
}
int main(void) 
{
    // insertAtBeg(2);
    // insertAtBeg(4);
    // insertAtBeg(6);
    // insertAtBeg(8);
    insertAtEnd(2);
    insertAtEnd(4);
    insertAtEnd(6);
    insertAtEnd(8);
    insertAtPos(1,3);
    insertAtPos(2,5);
    insertAtPos(4,7);
    insertAtPos(5,9);
    insertAtPos(9,100);
    printList();
    // printForwardListRecursively(head);
    // printf("\n");
    printReverseListRecursively(head);
	return 0;
}


