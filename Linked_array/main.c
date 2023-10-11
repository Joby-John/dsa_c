//probably ill abort this mission its too complicated to implement or might continue if i have free time.
#include<stdio.h>
#include<stdlib.h>
struct arr_cr{
    int full_size;
    int usable_size;
    int used_size;
    int* temp_addr;
    int* head;
};

void create_fresh(struct arr_cr* array_creator)
{
    int choice;
    printf("Enter the size of the array you want to create:- ");
    scanf("%d",&array_creator->usable_size);
    array_creator->full_size = array_creator->usable_size+1;
    array_creator->head = (int*)malloc(array_creator->full_size*sizeof(int));
    array_creator->head[array_creator->usable_size] = NULL;
    array_creator->used_size = 0; 
    while(array_creator->used_size<array_creator->usable_size)
    {
        printf("Enter the element you want to insert:- ");
        scanf("%d",&array_creator->head[array_creator->used_size]);
        printf("Do you want to insert another element sequentially,1/0:- ");
        scanf("%d",&choice);
        if(choice == 1){
        array_creator->used_size++;
        }
        else
        {
            break;
        }

    }
    if(array_creator->used_size >= array_creator->usable_size){
    printf("Current array is exhausted do you want to create another array. 1/0:- ");
    scanf("%d", &choice);
    }

}

void main()
{
    struct arr_cr array_creator;
    create_fresh(&array_creator);
    if(NULL==array_creator.head[array_creator.usable_size])
    {
        printf("Its null bro success\n");
    }
}