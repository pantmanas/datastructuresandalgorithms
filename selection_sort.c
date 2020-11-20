#include<stdio.h>

int * selectionSort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int minKey = array[i];
        int position = i;
        
        for(int j = i + 1; j < size; j++)
        {
            if(minKey > array[j])
            {
                minKey = array[j];
                position = j;
            }
        }
        if (i != position)
        {
            int temp = array[i];   
            array[i] = array[position];
            array[position] = temp;
        }
    }

    return array;
}

int main()
{
    //int arr[] = {7, 11, 9, 2, 17, 4};
    int arr[] = {12, 54, 65, 7, 23, 9};
    //int arr[] = {7, 11, 23, 32, 44, 49};
    //int arr[] = {1, 2, 5, 6, 12, 54, 625, 7 ,23, 9, 987};

    int size = sizeof(arr)/sizeof(int);

    int *output = selectionSort(arr, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", output[i]);
    }

    return 0;
}