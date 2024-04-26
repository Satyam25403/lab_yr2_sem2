//works good
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int parent[MAX];
int find(int i);
int union1(int i,int j);
int main(){
    int min,mincost=0,cost[MAX][MAX];
    int i,j,k,n,a,b,u,v,ne=1;
    printf("Enter number of vertices:");
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

    while(ne<n){
        min=9999;
        //to select n-1 edges
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);v=find(v);
        if(union1(u,v)){
            printf("%d edge (%d,%d)=%d\n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=9999;
    }
    printf("Minimum cost=%d\n",mincost);
    return 0;
}
int find(int i){
    while(parent[i]){
        i=parent[i];
    }
    return i;
}
int union1(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}