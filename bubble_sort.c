#include<stdio.h>

/*
int * bubbleSort(int array[], int size)
{   
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[i]>array[j])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    return array;
} */

int * bubbleSorted(int array[], int size)
{   
    int sorted = 1; //flag that checks if the array is already sorted
    for(int i = 0; i< size - 1; i++) // this is the loop for number of passes n-1
    {
       
        for(int j = 0; j < size - 1 - i; j++) // this is the loop for number of comparisons within each pass
        {
            int x = j + 1;
            if(array[j] > array[x])
            {
                int temp = array[x];
                array[x] = array[j];
                array[j] = temp;
                sorted = 0;
            }
        }
        if (sorted != 0)
        {
            break;
        }
    }
    return array;
} 

int main()
{
    //int arr[] = {7, 11, 9, 2, 17, 4};
    //int arr[] = {12, 54, 65, 7, 23, 9};
    //int arr[] = {7, 11, 23, 32, 44, 49}; // this array is already sorted
    int arr[] = {1, 2, 5, 6, 12, 54, 625, 7 ,23, 9, 987};

    int size = sizeof(arr)/sizeof(int);

    int *output;
    output = bubbleSorted(arr, size);

    for(int x = 0; x < size; x++)
    {
        printf("%d ", output[x]);
    }
    return 0;
}