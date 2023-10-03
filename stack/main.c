#include<stdio.h>
int top = -1;
void push(int* stack, int size)
{
    int data;
    printf("Enter element to push to stack:- ");
    scanf("%d",&data);
    if (top < size-1)
    {
        top++;
        stack[top] = data;
    }
    else
    {
        printf("The stack is full! OVERFLOW\n");
    }

}
void pop(int* stack)
{
    if (top >-1)
    {
        printf("The element to be popped = %d\n", stack[top]);
        top--;
    }
    else
    {
        printf("The stack is already empty!, UNDERFLOW\n");
    }
}

void display(int* stack)
{
    int i = 0;
    for (i; i<top;i++)
    {
        printf("%d,",stack[i]);
    }
    if (top>-1){
    printf("%d\n",stack[i]);
    }
    else
    {
        printf("Empty list!\n");
    }
}
void main()
{
    int choice, on = 1, size; 
    printf("Enter the size of the stack:- ");
    scanf("%d",&size);
    int stack[size];;
    while(on == 1)
    {
         printf("Enter your choice:- 1- push/2-pop/3-display/4-quit:-");
         scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   push(stack, size);
                   break;
            case 2: pop(stack);
                   break;
            case 3: display(stack);
                   break;
            case 4: on = 0;
                   break;
            default: printf("Invalid choice try again\n");
                    break;       

        }
    }
}