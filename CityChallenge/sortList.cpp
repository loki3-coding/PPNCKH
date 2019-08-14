#include "sortList.h"

void swap(int *a, int *b) 
{ 
    for (int i = 0; i < MAX_CLASS; i++) {
        int c = a[i];
        a[i] = b[i];
        b[i] = c;
    }
} 

int compareListMember(const int *A, const int *B){ 
    /*
    use: compare 2 element in struct [frame, xmin, ymin, xmax, ymax],
        return true if a < b, false otherwise.
    input:
        A   -   int*
            [frame, xmin, ymin, xmax, ymax]
        B   -   int*
            [frame, xmin, ymin, xmax, ymax]
    output:
        bool(A<B)
    */
    for (int i = 0; i < MAX_CLASS; i++){
        if (A[i] < B[i])
            return 1;
        if (A[i] > B[i])
            return 0;
    }
    return 0;
}

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int **arr, int low, int high) 
{ 
    int pivot[5];
    // pivot
    for (int j = 0; j < MAX_CLASS; j++)
        pivot[j] = arr[high][j];    
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (compareListMember(arr[j], pivot))
        { 
            i++;    // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int **arr, int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void sortList(int **Data, const int &lenData){
    quickSort(Data, 0, lenData-1);
}

