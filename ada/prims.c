#include <stdio.h>

void read_data(int n, int a[10][10]){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void prims(int n, int a[10][10]){
    int i, j, u, v, min;
    int sum;
    int t[10][2];
    int p[10];
    int d[10];
    int s[10];
    int source;
    min = 999;
    source = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) {
            if(a[i][j] != 0 && a[i][j] <= min){
                min = a[i][j];
                source = i;
            }
        }
    }
 for(i = 0; i < n; i++){
        d[i] = a[source][i];
        s[i] = 0;
        p[i] = source;
    }
    s[source] = 1;
    sum = 0;
    int k = 0;
    for(i = 1; i < n; i++){
        min = 999;
        u = -1;
        for(j = 0; j < n; j++){
            if(s[j] == 0){
                if(d[j] <= min){
                    min = d[j];
                    u = j;
                }
            }
        }
        t[k][0] = u;
        t[k][1] = p[u];
        sum += a[u][p[u]];
        s[u] = 1;
        for(v = 0; v < n; v++){
                        if(s[v] == 0 && a[u][v] < d[v]){
                d[v] = a[u][v];
                p[v] = u;
            }
        }
        k++;
    }

    if(sum >= 999){
        printf("Spanning tree does not exist");
    }
    else{
        printf("Spanning tree exists and minimum spanning tree is\n");
        for(i = 0; i < n - 1; i++){
            printf("Edge %d %d->%d\n", k, t[i][0], t[i][1]);
        }
        printf("The cost of the spanning tree = %d\n", sum);
    }
}

void main(){
    int cost[10][10], n;
    printf("Enter the number of nodes in the graph\n");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix\n");
    read_data(n, cost);
    prims(n, cost);
}


