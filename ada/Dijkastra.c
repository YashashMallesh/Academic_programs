#include <stdio.h>
#include<stdlib.h>
#define MV 10
#define INF 99
int p[MV];
int d[MV];
int visited[MV];
int dijk(int a[MV][MV],int s,int n){
    int u,v,i,j,min;
    for(v=0;v<n;v++){
        d[v] = INF;
        p[v] = -1;
        visited[v] = 0;
    }
d[s] = 0;
for(i=0;i<n;i++){
    min = INF;
    for(j=0;j<n;j++){
        if(d[j]<min && visited[j]==0){
            min = d[j];
            u=j;
        }
    }
    visited[u]=1;
    for(v=0;v<n;v++){
        if((d[u]+a[u][v]<d[v])&&u!=v&&visited[v]==0){
            d[v]=d[u]+a[u][v];
            p[v]=u;
        }
    }
}
}
void path(int v,int s){
    if(p[v]!=-1)
        path(p[v],s);
    if(v!=s)
        printf("->%d",v);
}
void display(int s,int n){
    int i;
    for(i=0;i<n;i++){
        if(i!=s){
            printf("%d",s);
            path(i,s);
        }
    if (d[i] >= 999) {
                printf("\nDistance: Unreachable\n");
            } else {
                printf("\nDistance: %d\n", d[i]);
            }
        }
}
int main() {
    int a[MV][MV];
    int i,j,n,s;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter weighted matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    printf("\nEnter src vertex:");
    scanf("%d",&s);
    dijk(a,s,n);
    printf("\nShortest path from src %d is:",s);
    display(s,n);
    return 0;
}
