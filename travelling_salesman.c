#include<stdio.h>
#include<limits.h>
#define V 4
int min(int,int);
int tsp(int graph[V][V],int visited[],int current,int count,int cost,int min_cost);

//function to find the minimum weight hamiltonian cycle
int tsp(int graph[V][V],int visited[],int current,int count,int cost,int min_cost){
    //if all vertices have been visited ,return the cost of cycle
    if(count==V && graph[current][0]){
        min_cost=min(min_cost,cost+graph[current][0]);
        return min_cost;
    }

    //try all unvisited nodes as next steps
    for(int i=0;i<V;i++){
        if(!visited[i] && graph[current][i]){
            //if vertex not visited and an edge is present
            visited[i]=1;
            //recursively find min cost from current vertex
            min_cost=tsp(graph,visited,i,count+1,cost+graph[current][i],min_cost);
            //backtrack :mark vrtex as unvisited
            visited[i]=0;
        }
    }
    return min_cost;
}
int main(){
    int graph[V][V]={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    int visited[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
    }
    //mark first node visited
    visited[0]=1;
    int min_cost=INT_MAX;
    printf("Minimun cost:%d\n",tsp(graph,visited,0,1,0,min_cost));
    return 0;
}
int min(int a,int b){
    return a<b?a:b;
}