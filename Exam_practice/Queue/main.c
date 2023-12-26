#include<stdio.h>

void main()
{
    int f=-1,r=-1, on = 1, opt;
    int arr[5];
    while(on)
    {
    printf("Enter 1 to enque 2 to dequeue 3-display and 4- quit: \n");
    scanf("%d", &opt);
    switch(opt){

        case 1 :
                if(r<4)
                {
                   f=0;
                   r+=1;
                   printf("Enter the element to enqueue\n");
                   scanf("%d", &arr[r]);
                }
                else
                {
                    printf("The queue is full\n");
                }
            break;

        case 2 :
               if(r>=f && f!=-1)
               {
                printf("Removed element is %d\n", arr[f]);
                f+=1;
               }    
               else
               {
                printf("The queue is empty\n");
                f=r=-1;
               }
               break;
        case 3:
               
               for(int i = 0; i<=r; i++)
               {
                 printf("%d ", arr[i]);
               }
               printf("\n");
               break;
        case 4:
               on = 0;       
    }             
}
}