#include <stdio.h>
#include <stdlib.h>



void swap(int *l, int *s )
{
    int temp = *s;
    *s = *l;
    *l = temp;
}

void bubbleSort(int arr[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
                 if(arr[j]>arr[j+1])
                 {
                     swap(&arr[j],&arr[j+1]);
                 }
        }

    }
}

void printArr(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}


int main()
{
    int arr[] = {64, 34,25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    printArr(arr,n);
    return 0;
}