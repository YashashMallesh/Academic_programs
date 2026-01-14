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
int main(){
int a[MAX],num,i;
  printf("Collision handled by linear probing");
  for(i=0;i<MAX;a[i++]=-1)
    do{
        printf("Enter the data");
        scanf("%d",&num);
        linear_prob(a,num,mod(num));
        printf("Do u wish to continue(0/1)");
        scanf("%d",&i);
    }while(1);
display(a);
  return 0;
}
