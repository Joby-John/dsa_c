#include<stdio.h>

void display(int arr[], int* size_now)
{
    for (int i = 0; i<*size_now-1; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d\n",arr[*size_now-1]);
}
void ind_add(int arr[], int* size)
{
     int index;
    printf("Enter the index you want to insert:- ");
    scanf("%d",&index);
    if (index>*size)
    {
        printf("Index you entered will produce vacant spaces so inserting in %d\n", *size);
        index = *size;
    }
    for(int i = *size-1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    printf("Enter the element you want to insert:- ");
    scanf("%d",&arr[index]);
    *size+=1;
}
int main()
{
    int size = 5;
    int arr[100] = {1,2,3,4,5};
    display(arr, &size);
    if (size<100){
    ind_add(arr, &size);
    }
    else{
        printf("Array is full");
    }
    display(arr,&size);
    return 0;
}