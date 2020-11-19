#include<stdio.h>

void displayArr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int searchBinary(int arr[], int size, int element)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            printf("\nelement bigger than mid value\n");
            low = mid + 1;    
        }
        else
        {
            printf("\nelement smaller than mid value\n");
            high = mid - 1;
        }
        
    }
    return -1;
}

int main()
{
    int arr[] = {2, 8, 14, 32, 66, 100, 104, 203, 400};
    int size = sizeof(arr) / sizeof(int);
    int element = 500, found = 0;
    displayArr(arr, size);
    found = searchBinary(arr, size, element);
    if (found != -1)
    {
        printf("\nelement found at index %d\n", found);
    }
    else
    {
        printf("\nelement NOT found\n");
    }
    return 1;
}