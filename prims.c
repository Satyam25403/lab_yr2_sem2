#include<stdio.h>
#define MAX 20
int main(){
    int a,b,u,v,n,i,j,sv,ne=1;
    int visited[MAX]={0},min,mincost=0,cost[MAX][MAX];
    printf("\n prims algorithm::Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            //if elements are not adjacent, mark their distances infinity
            if(cost[i][j]==0){
                cost[i][j]=9999;
            }
        }
    }
    printf("\nEnter the source vertex:");
    scanf("%d",&sv);
    visited[sv]=1;

    while(ne<n){
        //In each iteration,find the minimum cost edge that connects a visited vertex to an unvisited vertex.
        min=9999;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    if(visited[i]!=0){
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0||visited[v]==0){
            printf("edge-%d :: (%d,%d)=%d\n",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=9999;
    }
    printf("Minimum cost=%d\n",mincost);
    return 0;
}