#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#define mod(x)%x(MAX)

void linear_prob(int a[],int num,int key){
if(a[key]==-1)
  a[key]=num;
else{
  printf("Collision detected");
  int i;
  for(i=mod(key+1);i!=key;i=mod(++i))
    if(a[i]==-1)
      break;
  if(i!=key){
    printf("Collision avoided successfully");
    a[i]=num;
  }
  else
    printf("Hash table full\n");
}
}
