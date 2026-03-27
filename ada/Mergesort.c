#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(long int arr[],long int low,long int mid,long int high){
  long int k = low;
  long int i = low;
  long int j = mid+1;
  long int temp[100000];
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
  
}
int main(){
  
}
