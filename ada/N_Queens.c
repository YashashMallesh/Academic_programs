#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int can_replace(int c[],int r){
  int i;
  for(i=0;i<r;i++)
    if(c[i]==c[r]||(abs(c[i]-c[r])==abs(i-r)))
      return 0;
  return 1;
}
void display(int c[],int r){
  char cb[10][10],i,j;
  for(i=1;i<n;i++)
    for(j=1;j<n;j++)
      cb[i][j]=='-';
  for(i=1;i<n;i++)
    cb[i][c[i]] = 'Q';
  for(i=1;i<n;i++){
    for(j=1;j<n;j++)
      printf("%c",c[i][j]);
  printf("\n");
}
}
void n_q(int n){
  int c[MAX];
  int r = 0; 
  c[0] = -1;
  while(r>=0)
    c[r]++;
    while(c[r]<n && !can_replace(c,r))
      c[r]++;
    if(c[r]<n){
      if(r==n-1){
        display(c,r);
        printf("\n\n");
      }
      else{
        r++;
        c[r] = -1;
      }
    }
    else{
      r--;
    }
  }
void main(){
  int n;
  printf("Enter no.of queens");
  scanf("%d",&n);
  n_q(n);
}
