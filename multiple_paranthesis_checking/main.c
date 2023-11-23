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

int pop(char brack)
{
    if(Stack.top>0)
    {
        switch(brack){
            case '{':
                  if (Stack.arr[Stack.top] == '{')
                  {
                    Stack.top -= 1;
                  }
            break;

            case '[':
                 if (Stack.arr[Stack.top] == '[')
                 {
                    Stack.top -= 1;
                 }            
            break;

            case '(':
                  if (Stack.arr[Stack.top]=='(')
                  {
                    Stack.top -= 1;
                  }     
            break;

            default:
                  break;      
        }
        return(Stack.top);
    }
    else if(Stack.top == 0)// if stack top is 0 and encounters a closing bracket
    {
        return (Stack.top-=1);
    }

}
int ParanthesisChecking(char* array)
{
    int r_val;
    for(int i = 0; i<strlen(array); i++)
    {
       switch(array[i]){
        case '{': push('{');
        break;
        case '(': push('(');
        break;
        case '[': push('[');
        break;
        case '}': r_val = pop('{');
        break;
        case ')': r_val = pop('(');
        break;
        case ']': r_val = pop('[');
        break;
        default: //printf("do nothing\n");
        break;
       }
       if (r_val<0) // to stop for as soon as some close bracket without a previous open is encountered
       {
        break;
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
    scanf("%s",&array);
    printf("Entered expression is %s\n", array);
    return_val = ParanthesisChecking(array);
    if (return_val>0)
    {
        printf("Unbalanced\n", Stack.arr[Stack.top]);
    }  
    else if (return_val<0)
    {
        printf("Unbalanced\n", Stack.top);
    } 
    else
    {
        printf("Balanced\n", Stack.top);
    }
    free(Stack.arr);
}