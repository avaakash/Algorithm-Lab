#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
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
    int buffer[10] = {1000,5000,10000,15000,20000,25000,50000,100000,500000,1000000};
    printf("Size\tAverage\t\tBest\t\tWorst\n");
    for(int j=0;j<10;j++){
        int arr[buffer[j]];
        int size = buffer[j];
        for (int i = 0; i < size; i++)
        {
            arr[i] = (rand() % 20) + 50;
        }
        clock_t t;
        t = clock();
        mergeSort(arr,0, size-1);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;

        clock_t t2;
        t2 = clock();
        mergeSort(arr,0, size-1);
        t2 = clock() - t2;
        double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;
        reverseArray(arr, 0, size-1);

        clock_t t3;
        t3 = clock();
        mergeSort(arr,0, size-1);
        t3 = clock() - t3;
        double time_taken3 = ((double)t3) / CLOCKS_PER_SEC;
        
        printf("%d\t%f\t%f\t%f\n",size,time_taken,time_taken2,time_taken3);
        }
        
    
    getchar();
    return 0;
}