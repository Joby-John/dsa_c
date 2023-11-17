#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node;
node* head = NULL;
node* temp = NULL;
void push()
{
   node* new = (node*)malloc(sizeof(node));
   printf("Enter the element to be pushed : ");
   scanf("%d",&new->data);
   if (head == NULL)
   {
    head = new;
    head->next = NULL;
   }
   else
   {
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = NULL;
   }
}

void pop()
{
    if (head == NULL)
    {
        printf("Pop not possible, stack is empty");
    }
    else{
    temp = head;
    node* prev = NULL;
    while(temp->next != NULL)
    {   prev = temp;
        temp = temp->next;
    }
    if(temp == head)
    {
        printf("Element popped : %d", temp->data);
        temp = head = NULL;
        free(temp);
        free(head);
    }
    else
    {
    prev->next = NULL;
    printf("Element popped : %d", temp->data);
    temp = NULL;
    free(temp);
    }
    }
}

void display()
{
    temp = head;
    if (head == NULL)
    {
        printf("The stack is empty");
    }
    else{
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    }
    
}
int main()
{
    int choice, on = 1;
    while(on){
    printf("\nEnter your choice 1:push , 2-pop, 3- display :- ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;    
        default:
            temp = head;
            while(temp!=NULL)
            {
               head = temp;
               temp = head->next;
               printf("Deleted: %d\n", head->data);

            }
            temp = head = NULL;
            free(temp);
            free(head);
            on = 0;
            printf("Bye");    
    }
    } 
    return 0;
}