#include<stdio.h>
#include<stdlib.h>


struct myArray
{
    int total_size;
    int prim_usable_size;
    int *start_addr;//will be used to store the start addr of the allocated memory

};

void createArray(struct myArray* marks, int t_size, int u_size)//recieves addr of created instance marks
{ marks->total_size = t_size;
  marks->prim_usable_size = u_size;
  marks->start_addr = (int*)malloc(t_size*sizeof(int)); //stores the allocated memory's start addr to start_addr 

}

void add(struct myArray *marks)
{
    for(int i = 0; i<marks->prim_usable_size;i++)
    {
    printf("Enter an element to insert:- ");
    scanf("%d", (&(marks->start_addr)[i]));//gets an element stores it in the i th position in marks 
    }
}
void get(struct myArray *marks)
{
    int ind;
    printf("Enter the index of which you want to acccess the element:- ");
    scanf("%d",&ind);
    printf("%d",(marks->start_addr)[ind]);
}

void display(struct myArray *marks)
{
    int i;
    for (i = 0; i< marks->prim_usable_size-1;i++)
    {
        printf("%d,",(marks->start_addr)[i]);//access marks ith element
    }
    printf("%d\n",marks->start_addr[i]);
}

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

int main()
{
    struct myArray marks;//creates a structure named marks
    createArray(&marks, 100, 5);//sends marks addr,max size and used size
    add(&marks);//&- passes addr *- deferences addr(reads it)
    display(&marks);
    get(&marks);
    ind_insert(&marks);
    display(&marks);




    return 0;
}