#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int buffer[2] = {500000,1000000};
    printf("Size\tAverage\t\tBest\t\tWorst\n");
    for(int j=0;j<2;j++){
        int arr[buffer[j]];
        int size = buffer[j];
        for (int i = 0; i < size; i++)
        {
            arr[i] = (rand() % 20) + 50;
        }
        clock_t t;
        t = clock();
        insertionSort(arr, size);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;

        clock_t t2;
        t2 = clock();
        insertionSort(arr, size);
        t2 = clock() - t2;
        double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;
        reverseArray(arr, 0, size-1);

        clock_t t3;
        t3 = clock();
        insertionSort(arr, size);
        t3 = clock() - t2;
        double time_taken3 = ((double)t3) / CLOCKS_PER_SEC;
        
        printf("%d\t%f\t%f\t%f\n",size,time_taken,time_taken2,time_taken3);
        }
        
    
    getchar();
    return 0;
}