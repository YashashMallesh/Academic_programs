/*It divides the array into a sorted and an unsorted part.
It repeatedly finds the minimum element from the unsorted part and swaps it with the first element of that part.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(long int *a,long int *b){
int temp = *a;
*a = *b;
*b = temp;  
}
void SelectSort(long int arr[],long int n){
  long int i,j,min;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++)
      if(arr[j]<arr[min])
        min=j;
    swap(&arr[min],&arr[i]);
  }
}
int main(){
  long int n = 5000;
  int iteration = 0;
  double time[10];
  printf("A_Size,Selection");
  while(iteration++<10){
    long int a[n];
    for(int i=0;i<n;i++){
      long int num = rand()%n+1;
      a[i]=num;
    }
    clock_t start,end;
    start = clock();
    SelectSort(a,n);
    end = clock();
    time[iteration] = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("%li %f",n,time[iteration]);
    n+=500;
  }
  return 0;
}
/*Selection Sort divides the array into a sorted and an unsorted region:

It scans the unsorted region to find the minimum element.

It swaps this minimum element with the first element of the unsorted region.

The boundary moves one element to the right, and the process repeats until the entire array is sorted.

The main function runs 10 iterations*/
/*DrawbacksPoor Scaling {O}(n^2): It becomes incredibly slow for large datasets.
Doubling the array size increases the execution time by roughly a factor of 4.

Not Adaptive: It does not care if the data is already perfectly sorted. It will stupidly run through every loop iteration anyway.
Unstable Sorting: It can change the relative order of elements with equal values. For example, if you sort [4a, 4b, 1], 4a will be swapped with 1, resulting in [1, 4b, 4a]. 
The original order of the fours is broken.

Hardware with Costly Write Operations: In flash memory (like EEPROM), writing data degrades the hardware much faster than reading it. 
Selection Sort performs at most {O}(n) swaps (writes), making it highly optimal when write-cycles are precious.
Strictly Auxiliary Memory Constrained Systems: Because it is an in-place algorithm requiring zero extra memory arrays, it works well in deeply embedded systems with just bytes of RAM.
Small Datasets: For tiny lists (e.g., n < 20), the overhead of complex algorithms like Quick Sort or Merge Sort makes Selection Sort perfectly acceptable and easy to debug.
*/
