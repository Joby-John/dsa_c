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

void insertion(){
    int choice;
    struct Node* new;
    int data;
    printf("Enter the value to insert in node:- ");
    scanf("%d",&data);
    new = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        head = new;
        head->value = data;
        head->next = NULL;
    }
    else
    {
        printf("enter 1- begining 2- in between 3-at end 4- after a node:- ");
        scanf("%d",&choice);
        temp = head;
        switch(choice){
            case 1:
            head = new;
            new->next = temp;
            new->value = data;
            printf("Insertion success\n");  

            break;

            case 2:
            int after, found = 1;
            temp = head;
            printf("After which value you want to insert :- ");
            scanf("%d", &after);
            while(temp!=NULL && temp->value!=after)
            {
                //printf("Working\n");
                temp = temp->next;
            }
            if(temp!=NULL){
            //printf("Working here\n");
            new->value = data;
            new->next = temp->next;
            temp->next = new;
            }
            else
            {
                printf("There is no such element\n");
            }

            break;

            case 3:
            while(temp->next!= NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            new->value = data; 
            new->next = NULL;
            printf("Insertion success!\n");

            break;

            case 4: 
            printf("Coming soon\n");
            //enter the adress of the node to which you want to attach
            //new.next = addr.next
            //addr.next = new

            break;
    }
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
        case 1: insertion();
                 break;
        case 2: display();
                break;
        default: clear_all();
                 on = 0;
                 break;                 
    }
    }
    
}


