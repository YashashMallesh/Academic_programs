// Also Known as Partition Exchange Sort.
/* Steps involved:
  Step 1: Choose a pivot element.
  Step 2: Parttion the array.
  Step 3: Recursive calls to the quicksort.
  Step 4: Base Case.
  */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(long int *a,long int *b){
  long int tmp = *a;
  *a = *b;
  *b = tmp;
}
long int partition(long int arr[],long int low,long int high){
  long int pivot = arr[high];
  long int i = low-1;
  for(long int j=low;j<=high;j++){
    if(arr[j]<=pivot){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return(i+1);
}
void quicksort(long int arr[],long int low,long int high){
  if(low<high){
    long int pi = partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
  }
}
int main(){
  long int n = 10000;
  int it = 0;
  double time[10];
  printf("A_Size,Quick\n");
  while(it++<10){
    long int a[n];
    for(int i=0;i<n;i++){
      long int num = rand()%n+1;
      a[i] = num;
    }
    clock_t start,end;
    start = clock();
    quicksort(a,0,n-1);
    end = clock();
    time[it] = ((double)(end-start)/CLOCKS_PER_SEC);
    printf("%li,%f\n",n,time[it]);
    n<=10000;
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
