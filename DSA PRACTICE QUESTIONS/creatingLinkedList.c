#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;



void push(node** head,int ndata){
    node* new=(node*)malloc(sizeof(node));
    new->data = ndata;
    new->next = *head;
    *head = new;
    
}

void deleteNode(node** head){
    node* temp;
    temp = *head;

    *head = (*head)->next;    
    free(temp);

}



void pop(node **stack){
    if(*stack==NULL){
        printf("Underflow");
    }
    else{
        deleteNode(stack);
    }
}

void printStack(node *stack) {
    node *x = stack;
    if(x!=NULL){
    while (x!= NULL) {
        printf("%d\t", x->data);
        x = x->next;
    }
    }

    else{
        printf("Stack is empty");
    }

}

void peek(node *stack){
    printf("%d\n",stack->data);
}

int main(){
node *head = NULL;
for(int i=0;i<5;i++){
    push(&head,i*10);
}

peek(head);   
pop(&head);
printStack(head);

}
