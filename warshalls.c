//works good
#include<stdio.h>
#define infinity 9999
#define max 20
int min(int a,int b);

int main(){
    int i,j,k,n;

    printf("\nEnter the number of vertices:");
    scanf("%d",&n);

    int adj[n][n],path[n][n];
    printf("enter the cost-adjacency matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0 && i!=j){
                path[i][j]=infinity;
            }
            else{
                path[i][j]=adj[i][j];
            }
        }
    }
    for(k=0;k<n;k++){
        //first loop to keep track of all via vertices
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
    printf("shortest path matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",path[i][j]);
        }
        printf("\n");
    }
}
int min(int a,int b){
    return a<b?a:b;
}