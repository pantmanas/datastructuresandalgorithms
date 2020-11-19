#include<stdio.h>

int binarySearch(int array[], int size, int value)
{

    int low = 0;
    int high = size - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(array[mid] == value)
        {
            return mid;
        }
        if(array[mid] > value)
        {
            high = mid+1;
        }
        if(array[mid] < value)
        {
            low = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {22, 45, 71, 109, 115, 127, 135};
    int element = 71;
    int size = sizeof(arr)/sizeof(int);

    int position = binarySearch(arr, size, element);
    if(position != -1)
    {
        printf("\nelement found at position: %d", position);
    }
    else
    {
        printf("\nelement not found");
    }
    return 0;
}