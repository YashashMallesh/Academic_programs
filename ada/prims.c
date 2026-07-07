#include<stdio.h>
int r = 1,mincost = 0;
void main(){
  int n,i,k,min,cost[20][20],a,u,b,v,src,vis[20];
  printf("\nEnter number of nodes:");
  scanf("%d",&n);
  printf("\nEnter the cost matrix:\n");
  for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
      scanf("%d",&cost[i][j]);
  for(i=1;i<=n;i++)
    vis[i] = 0;
  printf("\nEnter the root node:");
  scanf("%d",&src);
  vis[src] = 1;
  printf("\nMinimum cost spanning tree is:\n");
  while(r<n){
    min = 999;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++) {
      if(cost[i][j]<min)
        if(vis[i]==0)
          continue;
      else{
        min=cost[i][j];
        a=u=i;
        b=v=j;
      }
    }
  }
    if(vis[u]==0||vis[v]==0){
      printf("\nEdge %d\t(%d->%d)=%d\n",r++,a,b,min);
      mincost = mincost + min;
      vis[b] = 1;
    }
    cost[a][b] = cost[b][a] = 999;
  }
  printf("\nMinimum cost=%d\n",mincost);
}
