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
 struct Node* new = NULL;

void insertion(){
    int choice;
    int data;
    printf("Enter the value to insert in node:- ");
    scanf("%d",&data);
    new = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        head = new;
        head->value = data;
        head->next = head;
    }
    else
    {
        printf("enter 1- begining 2- in between 3-at end 4- after a node:- ");
        scanf("%d",&choice);
        temp = head;
        switch(choice){
            case 1:
            temp = head;
            new->next = temp;
            new->value = data;
            while(temp->next!=head)
            {
                temp = temp->next; 
            }
            temp->next = new;
            head = new;
           

            break;

            case 2:
            int after, found = 0;
            temp = head;
            printf("After which value you want to insert :- ");
            scanf("%d", &after);
            if(head->value != after)
            {
            do
            {
                //printf("Working\n");
                temp = temp->next;
            }while(temp!=head && temp->value!=after);
            }
            else
            {
            new->value = data;
            new->next = temp->next;
            temp->next = new;
            found = 1;
            }

            if(temp!=head){
            //printf("Working here\n");
            new->value = data;
            new->next = temp->next;
            temp->next = new;
            found = 1;
            }
            if(!found)
            {
                printf("There is no such element\n");
            }

            break;

            case 3:
            while(temp->next!= head)
            {
                temp = temp->next;
            }
            temp->next = new;
            new->value = data; 
            new->next = head;
            printf("Insertion success!\n");

            break;

            case 4: 
            temp = head;
            struct Node* addr;
           printf("Here is the address of all the nodes yet created:- ");
           if(head->next==head)
           {
             printf("%d- %p", temp->value,temp);
           }
           else{
            temp = temp->next;
            printf("%d- %p\n", head->value,head);
           while(temp!=head)
           {
            printf("%d-%p,", temp->value,temp);//pointer should be displayed as address and place holder %p should be used
            temp = temp->next;
           }
           }
           temp = head;
           printf("Now enter the correct adress of the of the node after which you want to insert:- ");
           scanf("%p",&addr);//like wise when dealing with address %p should be used not %d 
           new->next = addr->next;
           new->value = data;
           addr->next = new;
           printf("Insertion success\n");

            break;

            default:
                    printf("Invalid entry\n");
                    break;
    }
    }
}
void display()
{
    if(head!=NULL){
    temp = head->next;
    //printf("head in display:- %d", head);
    printf("%d,",head->value);
    while(temp!= head)
    {
        printf("%d,",temp->value);
        temp = temp->next;
    }
    }
    else{
        printf("The list is empty \n");
    }

}

void delete()
{
    temp = head;
    struct Node* prev = NULL;
    if(head == NULL)
    {
        printf("The list is empty add some elemnets first\n");
    }
    else{
        int choice, del_pos ,counter = 1;
        printf("choose an option 1- first node, 2-node after, 3-last node, 4- given value:-");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                   temp = head;
                   head = head->next;
                   free(temp);
                   temp = NULL;
                   printf("Deletion complete\n");
                   temp = head;
                   break;
            case 2:
                   printf("After which node you want to delete enter 1,2..:-");
                   scanf("%d", &del_pos);
                   while(counter!=del_pos)
                   {
                    if(temp == head)
                    {
                        printf("Entered index is unreachable\n");
                        break;
                    }
                    else{
                        prev = temp;
                        temp = temp->next;
                        counter += 1;

                    }
                   }
                   if(temp == head)
                   {
                    if(temp->next == NULL)
                    {
                        free(temp);
                        temp = NULL;
                    }
                    else{
                    temp = head;
                    head = head->next;
                    free(temp);
                    }
                   }
                   else{
                    prev->next = temp->next;
                    free(temp);
                    temp = NULL;
                   }
                   printf("Deletion success\n");
                   
            break;
            case 3:
                if (head->next == NULL)
                {
                    free(head);
                    head = NULL;
                }
                else{
                while(temp->next!=NULL)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
                free(temp);
                temp = NULL;
                }
                printf("Deletion success\n");

            break;
            case 4:
                  int found = 1;
                  printf("Enter the value that is to be deleted from the list:- ");
                  scanf("%d",&del_pos);
                  while(temp->value != del_pos)
                  {
                    prev = temp;
                    temp = temp->next;
                    if (temp == NULL)
                    {
                        found = 0;
                        break;
                    }
                  }
                  if (found){
                  if(temp == head)
                   {
                    if(temp->next == NULL)
                    {
                        free(temp);
                        temp = NULL;
                        head = NULL;
                    }
                    else{
                    temp = head;
                    head = head->next;
                    free(temp);
                    }
                   }
                   else{
                    prev->next = temp->next;
                    free(temp);
                   }
                   printf("Deletion success\n");
                  }
                  else
                  {
                    printf("No such element\n");
                  }
            break;
            default: printf("Looks like you entered wrong key\n");
                     break;       


        }
    }
}

void clear_all()
{
    struct Node* next;
    temp = head;
    if (head!=NULL)
    {  
    while(temp->next!=head)
    {
        next = temp->next;
        printf("Deleting:- %d\n", temp->value);
        free(temp);//first node to be freed is head
        temp = next;
    }

        printf("Deleting:- %d\n", temp->value);
    }
    temp = NULL;
    free(temp);
    head = NULL;
    next = NULL;
    free(next);
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
        case 3: delete();
                 break;        
        default: clear_all();
                 on = 0;
                 break;                 
    }
    }
    
}


