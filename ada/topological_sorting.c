//Directed Acyclic Graph. Uses DFS for soring elements.
/* Linear ordering of vertices such that if there is an edge bw u&v, u appears befor v in that ordering.
Note down the nodes adjacent to the node we are visiting.
Insert the nodes we are visiting at the top of the stack.
If the top has all the adjacent nodes visited and there are no adjacent nodes to visit pop the top of the stack
After popping all the elements note down the resulting sorted list*/

#include<stdio.h>
int temp[10],k=0;
void sort(int a[][10],int id[],int n){
 int i,j;
 for(i=1;i<=n;i++){
  if(id[i]==0){
   id[i] = -1;
   temp[++k] = i;
   for(j=1;j<=n;j++){
    if(a[i][j]==1 && id[j]!=-1)
     id[j]--;
   }
   i = 0;
  }
 }
}
void main(){
 int a[10][10],id[10],n,i,j;
 printf("\nEnter the n value:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
  id[i] = 0;
 printf("\nEnter graph data:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++){
   scanf("%d",&a[i][j]);
   if(a[i][j]==1)
    id[j]++;
  }
 sort(a,id,n);
 if(k!=n)
  printf("\nTopological ordering not possible.");
 else{
  printf("\n Topological ordering is:\n");
  for(i=1;i<=k;i++)
   printf("%d",&temp[i]);
 }
}
