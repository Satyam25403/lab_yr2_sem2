//works good
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void dfs(int src);
int g[MAX][MAX],n,visited[MAX];

int main(){
    int i,j,s;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    printf("\nAdjacency Matrix:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        visited[i]=0;
    }
    printf("\nEnter starting vertex:");
    scanf("%d",&s);
    printf("\nDFS of the graph:");
    dfs(s);

}
void dfs(int src){
    int j;
    visited[src]=1;
    printf("%d\t",src); //output is numbers from 1 to a given range
    for(j=1;j<=n;j++){
        if((g[src][j]==1)&&(visited[j]==0)){
            dfs(j);
        }
    }
}