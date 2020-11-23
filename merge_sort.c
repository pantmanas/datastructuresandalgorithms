#include<stdio.h>

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int * merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    int output[100];

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            output[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            output[k] = arr[j];
            j++;
            k++;
        }

    }

    while(i <= mid)
    {
        output[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        output[k] = arr[j];
        j++;
        k++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = output[i];
    }

    return arr;

}

int * mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {   
        int mid = (low + high) / 2;
        arr = mergeSort(arr, low, mid);
        arr = mergeSort(arr, mid + 1, high);
        arr = merge(arr, low, mid, high);
    }
    return arr;
}

int main()
{
    int arr[] = {7, 9, 1, 3, 6, 8, 27, 2};
    //int arr[] = {9, 14, 4, 8, 7, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    printf("\narray before sorting\n");
    printArray(arr, n);

    int *output;
    output = mergeSort(arr, 0, n-1);

    printf("\n\narray after sorting\n");
    printArray(output, n);

    return 0;
}