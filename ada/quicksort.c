// Also Known as Partition Exchange Sort.
/* Steps involved:
  Step 1: Choose a pivot element. The code picks the last element as the pivot: long int pivot = arr[high];
  Step 2: Parttion the array. It scans the array from low to high. Any element smaller than or equal to the pivot is swapped to the left side using a tracking index i. Finally, the pivot is swapped into its correct sorted position (i + 1).
  Step 3: Recursive calls to the quicksort. The algorithm recursively sorts the left subarray (elements before the pivot) and the right subarray (elements after the pivot).
  Step 4: Base Case.
  */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(long int *a,long int *b){
    long int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(long int a[],long int low,long int high){
    long int i = low-1;
    long int pivot = a[high];
    for(long int j=low;j<high;j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return(i+1);
}
void quick(long int a[],long int low,long int high){
    if(low<high){
        long int pi = partition(a,low,high);
        quick(a,low,pi-1);
        quick(a,pi+1,high);
    }
}
int main(){
    long int n = 5000;
    double time[10000];
    int iteration = 0;
    printf("A_Size,Quick Sort\n");
    while(iteration++<10){
        long int a[n+1];
        for(int i=0;i<n;i++){
            long int num = rand()%n+1;
            num = a[i];
        }
        clock_t start,end;
        start = clock();
        quick(a,0,n-1);
        end = clock();
        time[iteration] = ((double)(end-start))/CLOCKS_PER_SEC;
        printf("%li,%f\n",n,time[iteration]);
    }
    return 0;
}
/*1. The Core Logic: Partitioning
The partition function is the "brain" of the algorithm. Its goal is to take a portion of the array and organize it around a pivot element.

Pivot Selection: In this code, the pivot is chosen as the last element: arr[high].

Reordering: It iterates through the array and moves every element smaller than or equal to the pivot to the left side.

The Result: After partitioning, the pivot is placed in its final, sorted position. Everything to its left is smaller, and everything to its right is larger.

2. The Recursive Strategy
The quicksort function handles the "divide" part:

It calls partition to find the correct spot for a pivot (let's call this index pi).

It then recursively calls itself for the "left" subarray (elements from low to pi - 1).

It recursively calls itself for the "right" subarray (elements from pi + 1 to high).

Base Case: The recursion stops when low is no longer less than high (meaning the subarray has one or zero elements).*/
/*Best Case {O}(n log n) Balanced partitions. The pivot always lands exactly in the middle, splitting the array into two equal halves at every step.
Average Case {O}(n log n) 
Typical random array distributions where the split is reasonably balanced.
Worst Case{O}(n^2)

Commercial Standard Libraries:
Virtual Memory / RAM-Constrained Environments*/
