#include<stdio.h>

int linearSearch(int arr[], int size, int element)
{
   for(int i = 0; i<size; i++)
   {
    if (arr[i] == element)
    {
        return i;
    }
   }
   return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int start = 0, end = size - 1; 
    int mid =  (start+end)/2;
    while(start <= end)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid]<element)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        mid = (start+end)/2;

    }
    return -1;
}

int main()
{
    int arr[] = {12,23,24,25,31,28,30};
    int size = 7, lin, bin;
    lin = linearSearch(arr, size, 30);
    printf("linear search found at : %d \n", lin+1);
    bin = binarySearch(arr, size, 30);
    printf("Binary search found at :%d", bin+1);
    return 0;
}