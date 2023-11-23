#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STACK{
    int size;
    char* arr;
    int top ;
} stacks;
stacks Stack;
void push(char bracks)
{
    char data = bracks;
    if (Stack.top < Stack.size-1)
    {
        Stack.top++;
        Stack.arr[Stack.top] = data;
    }

}

void pop()
{
    if(Stack.top>=0)
    {
        Stack.top-=1;
    }

}
int ParanthesisChecking(char* array)
{
    for(int i = 0; i<strlen(array); i++)
    {
        if(array[i]=='(')
        {
            push('(');
        }
        else if(array[i]==')')
        {
            pop();
        }
    }
    return Stack.top;

}
int main()
{   int return_val, size;
    printf("Enter the size of the expression: ");
    scanf("%d", &size);
    Stack.size = size;
    Stack.top = 0;
    char array[size];
    Stack.arr = (char*)malloc(size*sizeof(char));
    printf("Enter your expression: ");
    scanf("%s",array);
    printf("Entered string is %s\n", array);
    return_val = ParanthesisChecking(array);
    if (return_val>0)
    {
        printf("Unbalanced, extra ( found\n", Stack.top);
    }  
    else if (return_val<0)
    {
        printf("Unbalanced, extra ) found\n", Stack.top);
    } 
    else
    {
        printf("Balanced\n", Stack.top);
    }
}