//works good
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 8
int graph[V][V];
int minDistancevertex(int dist[],bool sptSet[]);
void printSolution(int dist[],int n);
void dijkstra(int graph[V][V],int src);

int main(){
    printf("Enter the array:\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    dijkstra(graph,0);
    return 0;
}
int minDistancevertex(int dist[],bool sptSet[]){
    int min=INT_MAX,min_index;
    //search for the vertex with minimum distance value from the set of vertices
    // not yet included in shortest path tree
    for(int v=0;v<V;v++){
        if(sptSet[v]==false && dist[v]<=min){
            min=dist[v];        //min is important for comparision of 
            //distance of prviously visited vertex and this vertex
            min_index=v;
        }
    }
    return min_index;
}
//print shortest distances from source to other vertices
void printSolution(int dist[],int n){
    printf("Vertex Distance from source:\n");
    for(int i=0;i<V;i++){
        printf("%d\t\t%d\n",i,dist[i]);
    }
}
void dijkstra(int graph[V][V],int src){
    //array to store the shortest distances to all the vertices
    int dist[V];
    bool sptSet[V];     //to mark the verices included in shortest path tree

    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[src]=0;

    for(int count=0;count<V-1;count++){
        int u=minDistancevertex(dist,sptSet);
        sptSet[u]=true;         //mark the selected vertex as processed
        for(int v=0;v<V;v++){
            //if vertex is not in sptset, there is edge from u to v, total weight of path from src to v through
            //u is smaller than the current value
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist,V);
}

