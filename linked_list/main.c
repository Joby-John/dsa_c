#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int value; 
    struct Node* next;
};
// creating two empty nodes to store adressses
struct Node* head = NULL;
struct Node* temp = NULL;

void creation(){
    struct Node* addr;
    int data;
    printf("Enter the value to insert in node:- ");
    scanf("%d",&data);
    addr = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        head = addr;
        head->value = data;
        head->next = NULL;
    }
    else
    {
        printf("Working");
        temp = head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = addr;
        addr->value = data; 
        addr->next = NULL;
    }
}
void display()
{
    temp = head;
    while(temp->next!= NULL)
    {
        printf("%d,",temp->value);
        temp = temp->next;
    }
    printf("%d\n",temp->value);

}

void clear_all()
{
    struct Node* next;
    temp = head;
    while(temp!= NULL)
    {
        next = temp->next;
        printf("Deleting:- %d\n", temp->value);
        free(temp);//first node to be freed is head
        temp = next;
    }
    temp = NULL;
    free(temp);
    head = NULL;
   //printf("%d,%d",head,temp);
    
}

void main()
{
    int choice, on = 1;
    while(on){
    printf("Enter you choice, 1.insert 2.display 3.quit:- ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: creation();
                 break;
        case 2: display();
                break;
        default: clear_all();
                 on = 0;
                 break;                 
    }
    }
    
}


