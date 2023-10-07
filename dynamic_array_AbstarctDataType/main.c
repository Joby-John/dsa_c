#include<stdio.h>
#include<stdlib.h>


struct myArray
{
    int total_size;
    int prim_usable_size;
    int *start_addr;//will be used to store the start addr of the allocated memory

};
// array creation and adding first five elements
int createArray(struct myArray* marks, int t_size, int u_size)//recieves addr of created instance marks
{ marks->total_size = t_size;
  marks->prim_usable_size = u_size;
  marks->start_addr = (int*)malloc(t_size*sizeof(int)); //stores the allocated memory's start addr to start_addr 
  if (marks->start_addr == NULL)
  {
    return -1;
  }
  for(int i = 0; i<marks->prim_usable_size;i++)
    {
    printf("Enter an element to insert:- ");
    scanf("%d", (&(marks->start_addr)[i]));//gets an element stores it in the i th position in marks 
    }
    return 0;
}

// this one is for regular adding
int add_last(struct myArray* marks)
{
    if (marks->prim_usable_size<marks->total_size){
              marks->prim_usable_size += 1;
              printf("Enter the element:- ");
              scanf("%d", &marks->start_addr[marks->prim_usable_size-1]);
              return 0;
          }
          else
          {
                 printf("The array is filled up\n");
                 return -1;            
          }
          
}

// to get an element at a specific index
void get(struct myArray *marks)
{
    int ind;
    printf("Enter the index of which you want to acccess the element:- ");
    scanf("%d",&ind);
    printf("%d\n",(marks->start_addr)[ind]);
}

void display(struct myArray *marks)
{
    if (marks->prim_usable_size>0){
    int i;
    for (i = 0; i< marks->prim_usable_size-1;i++)
    {
        printf("%d,",(marks->start_addr)[i]);//access marks ith element
    }
    printf("%d\n",marks->start_addr[i]);
    }
    else
    {
        printf("Trying to print an empty list\n ");
    }
}

// To insert at a specific index
int ind_insert(struct myArray* marks)//inserts at specified index
{
    int index;
    if (marks->prim_usable_size >= marks->total_size)
    {
        return -1;
    }
    printf("\nAt which index do you want to insert:- ");
    scanf("%d",&index);
    for (int i = marks->prim_usable_size-1; i>=index; i-- )
    {
        marks->start_addr[i+1] = marks->start_addr[i];

    }
     printf("Enter the term you want to insert :- ");
     scanf("%d",&marks->start_addr[index]);
     marks->prim_usable_size++;
     return 0;
}

// delete at a specific index

int ind_Delete(struct myArray* marks)
{
    int index;
    printf("Enter the index you want to delete:- ");
    scanf("%d",&index);
    if(index<=marks->prim_usable_size-1&&index>=0)//so that user doesnt enter any out of limit number
    {
        if(index == marks->prim_usable_size-1)
        {
            marks->prim_usable_size -= 1;
            printf(" size now:- %d\n", marks->prim_usable_size);
        }
        else
        {
            for (int i = index; i<marks->prim_usable_size; i++)
            {
                //printf("Works\n");
                marks->start_addr[i] = marks->start_addr[i+1];
            } 
            marks->prim_usable_size -= 1;
            //printf(" size now:- %d\n", marks->prim_usable_size);
        }
        return 0;
    }
    else{
        printf("Trying to delete at an impossible position\n");
        return -1;
    }
}

int main()
{
    struct myArray marks;//creates a structure named marks
    int choice, on = 1;
    createArray(&marks, 100, 5);//sends marks addr,max size and used size
    while(on){
        printf("Enter the choice :- 1.add,2.display,3.get,4.insert at index, 5.delete, anyother.quit:- ");
        scanf("%d",&choice);
    switch(choice) {
    case 1: add_last(&marks);//&- passes addr *- deferences addr(reads it)
            break;
    case 2: display(&marks);
            break;
    case 3: get(&marks);
            break;
    case 4: ind_insert(&marks);
            break;
    case 5: ind_Delete(&marks);
            break;        
    default: 
             printf("Exiting\n");
             free(marks.start_addr);
             on = 0;

    }
    }
    return 0;
}