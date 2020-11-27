#include<stdio.h>

void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int findMax(int a[], int n)
{
    int x = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(a[i] > x)
        {
            x = a[i];
        }
    }

    return x;
}

void countSort(int a[], int n)
{
    int max = findMax(a, n);
    int countArr[max+1];

    //initialize all elements of countArr with 0 values
    for(int i = 0; i < max+1; i++)
    {
        countArr[i] = 0;
    }

    int index = 0;

    //set the values in countArr, increment by 1 for index whose value is equal to the value of each element in a
    for(int k = 0; k < n; k++)
    {
        index = a[k];
        countArr[index] = countArr[index] + 1;
    }

    //iterating through countArray to overwrite the original array a with countArray's indexes
    int r = 0;
    for(int j = 0; j < max+1; j++)
    {
        while(countArr[j] != 0)
        {
            a[r] = j;
            r++;
            countArr[j]--;
        }
    }
}

int main()
{
    int a[] = {3, 1, 9, 7, 1, 2, 4};
    int n = sizeof(a)/sizeof(int);

    printf("\narray before sorting\n");
    printArray(a, n);

    countSort(a, n);

    printf("\narray after sorting\n");
    printArray(a, n);

}