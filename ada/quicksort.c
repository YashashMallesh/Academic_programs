#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(long int *a,long int *b){
  long int tmp = *a;
  *a = *b;
  *b = tmp;
}
