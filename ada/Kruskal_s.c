#include<stdio.h>
#include<stdlib.h>

int find(int v, int s[]){
  while(s[v]!=v)
    v = s[v];
  return v;
}
void kruskal(int n, int c[10][10]){
  int count, i, s[10], min, j, u, v, k, t[10][2], sum;
  for(i=0;i<n;i++)
    s[i] = i;
  count = 0;
  sum = 0;
  k = 0;
  while(count<n-1){
    min = 9999;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(c[i][j]!=0 && c[i][j]<min){
          min = c[i][j];
          u = i;
          v = j;
        }
      }
    }
    if(min == 9999)
      break;
    i = find(u,s);
    j = find(v,s);
    if(i!=j){
      t[k][0] = u;
      t[k][1] = v;
      k++;
      count++;
      sum+=min;
      s[v] = u;
    }
    c[u][v] = c[v][u] = 9999;
  }
  if(count = -1){
    printf("Cost of Spanning Tree = %d\n",sum);
    printf("Spanning tree is given below:\n");
    for(k=0;k<n-1;k++)
      printf("%d,%d\n",t[k][0],t[k][1]);
    exit(0);
  }
  printf("Spanning tree does not exist.\n");
}
void main(){
  int n, c[10][10], i, j;
  printf("Enter no of nodes:\n");
  scanf("%d\n",&n);
  printf("Enter adjacency matrix:\n");
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",&c[i][j]);
  kruskal(n,c);
}
