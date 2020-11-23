#include<stdio.h>

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while(arr[i] <= pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;    
    return j;
}

int * quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int partitionIndex = partition(arr, low, high);
        arr = quickSort(arr, low, partitionIndex - 1);
        arr = quickSort(arr, partitionIndex + 1, high);
    }

    return arr;
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    //int arr[] = {1, 2, 3, 9, 4, 4, 8, 7, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = n-1;

    printf("array before sorting\n");
    printArray(arr, n);
    
    int *output;
    output = quickSort(arr, low, high);

    printf("\n\narray after sorting\n");
    printArray(output, n);

    return 0;
}