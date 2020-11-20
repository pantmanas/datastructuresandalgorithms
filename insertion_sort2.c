#include<stdio.h>

int * insertionSort(int array[], int size)
{
    for(int i = 0; i < size-1; i++) // the loop for each pass, there have to be n-1 passes in total
    {
        int key = array[i+1];
        
        for(int j = i; j >= 0; j--) // the loop for comparisons within each pass, start with 1, increase the number
                                       // by 1 in each pass
        {
            if(key < array[j])
            {
                int temp = array[j];
                array[j] = key;
                array[j+1] = temp;
            }
            if(key >= array[j])
            {
                break;
            }
        }
    }
    return array;
}

int main()
{
    //int arr[] = {7, 11, 9, 2, 17, 4};
    //int arr[] = {12, 54, 65, 7, 23, 9};
    //int arr[] = {7, 11, 23, 32, 44, 49};
    int arr[] = {1, 2, 5, 6, 12, 54, 625, 7 ,23, 9, 987};

    int size = sizeof(arr)/sizeof(int);

    int *output;
    output = insertionSort(arr, size);
    
    int i = 0;
    while(i<size)
    {
        printf("%d ", output[i]);
        i++;
    }
    

    return 0;
}