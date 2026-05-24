#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(long int arr[],long int low,long int mid,long int high){
  long int k = low;
  long int i = low;
  long int j = mid+1;
  long int temp[10];
  while(i<=mid && j<=high){
    if(arr[i]<=arr[j]){
      temp[k] = arr[i];
      i++;
      k++;
    }
    else{
      temp[k] = arr[j];
      j++;
      k++;
    }
  }
  while(i<=mid){
    temp[k]  = arr[i];
    i++;
    k++;
  }
  for(i=low;i<=high;i++)
    arr[i] = temp[i];
  }
void mergesort(long int arr[],long int low,long int high){
  if(low<high){
    long int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}
int main(){
  long int n = 10000;
  int it = 0;
  double time[10];
  printf("A_Size,Merge\n");
  while(it++<10){
    long int a[n];
    for(int i=0;i<n;i++){
      long int num = rand()%n+1;
      a[i] = num;
    }
    clock_t start,end;
    start = clock();
    mergesort(a,0,n-1);
    end = clock();
    time[it] = ((double)(end-start)/CLOCKS_PER_SEC);
    printf("%li,%f\n",n,time[it]);
    n+=10000;
  }
  return 0;
}

//Uses Dividde and conquer technique for sorting the array.
/*mergesort(arr, low, high) (The Divide Step): It finds the middle point mid = (low + high) / 2 to split the array into two halves. It then recursively calls itself to sort the left half (low to mid) and the right half (mid + 1 to high).

merge(arr, low, mid, high) (The Conquer & Combine Step): This is where the actual sorting happens.
It takes two pre-sorted sub-arrays and merges them into a single sorted sequence using a temporary auxiliary array (temp[100000]).
It compares elements from both halves one by one and copies the smaller element into temp. Finally, it copies the sorted elements back into the original array.
Best Case O(n log n) Even if the array is already sorted, the algorithm still splits it entirely and executes all merge steps.
Average Case O(n log n) Typical behavior on randomized datasets.
Worst Case O(n log n)
Inversion Counting:
External Sorting:
E-Commerce and Data Presentation.*/
