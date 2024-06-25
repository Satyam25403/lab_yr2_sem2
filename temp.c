#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 100
#define infinity 9999
#define V 8
struct item{
    int profit;
    int weight;
    double ratio;
    int index;
};
struct min_max{
    int min;
    int max;
};
struct min_max find_min_max(int arr[],int low,int high);
void knapsack(int w,struct item items[],int n);
//bfs
int g[MAX][MAX],visited[MAX],queue[MAX],graph[V][V];
// int front=-1,rear=-1,n;
// void dfs(int src);
// int mindistvertex(int dist[V],bool sptset[V]);
// void printsol(int dist[V]);
// void dijkstras(int graph[V][V],int src);
int min(int a,int b);
// int is_full();
// int is_empty();
// int dequeue();
// void enqueue(int n);
int bin(int arr[],int key,int l,int h);

// int main(){
//     int n,s,v;
//     printf("Enter number of vertices:");
//     scanf("%d",&n);

//     for(int i=0;i<n;i++){
//         visited[i]=0;
//         queue[i]=0;
//     }

//     printf("enter adjecency matrix:");
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             scanf("%d",&g[i][j]);
//         }
//     }
//     printf("enter starting vertex of graph:");
//     scanf("%d\t",&s);
//     printf("bfs of graph:");
//     enqueue(s-1);
//     visited[s-1]=1;
//     printf("%d",s);
//     while(!is_empty()){
//         v=dequeue();
//         for(int w=0;w<n;w++){
//             if(g[v][w] && !visited[w]){
//                 visited[w]=1;
//                 printf("%d\t",w+1);
//                 enqueue(w);
//             }
//         }
//     }
//     printf("\n");
//     return 0;
// }
// void enqueue(int n){
//     if(is_full()){
//         printf("queue is full");
//         exit(1);
//     }
//     if(front==-1){
//         front=0;
//     }
//     queue[++rear]=n;
// }
// int dequeue(){
//     int n;
//     if(is_empty()){
//         printf("queue is already empty");
//         exit(1);
//     }
//     if(front==rear){
//         n=queue[front];
//         front=rear=-1;
//     }
//     else{
//         n=queue[front++];
//     }
//     return n;
// }
// int is_empty(){
//     return (front==-1||front>rear);
// }
// int is_full(){
//     return rear==MAX-1;
// }
// int main(){
//     int src;
//     printf("enter number of vertices:");
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//         visited[i]=0;
//     }
//     printf("enter adjacency matrix:");
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             scanf("%d",&g[i][j]);
//         }
//     }
//     printf("\nenter the starting vertex:");
//     scanf("%d",&src);
//     dfs(src);
//     return 0;
// }
// void dfs(int src){
//     visited[src]=1;
//     printf("%d\t",src);
//     for(int i=1;i<=n;i++){
//         if(g[src][i] && visited[i]==0){
//             dfs(i);
//         }
//     }
// }
// int main(){
//     printf("Enter the adjacency matrix");
//     for(int i=0;i<V;i++){
//         for(int j=0;j<V;j++){
//             scanf("%d",&graph[i][j]);
//         }
//     }
//     dijkstras(graph,0);
//     return 0;
// }
// int mindistvertex(int dist[V],bool sptset[V]){
//     int min=INT_MAX,min_index;
//     for(int i=0;i<V;i++){
//         if(sptset[i]==false && dist[i]<=min){
//             min=dist[i];
//             min_index=i;
//         }
//     }
//     return min_index;
// }
// void printsol(int dist[V]){
//     printf("vertex\tshtest distance\n\n");
//     for(int i=0;i<V;i++){
//         printf("%d\t%d\n",i,dist[i]);
//     }
// }
// void dijkstras(int graph[V][V],int src){
//     int dist[V];
//     bool sptset[V];
//     for(int i=0;i<V;i++){
//         dist[i]=INT_MAX;
//         sptset[i]=false;
//     }
//     dist[src]=0;
//     for(int count=0;count<V-1;count++){
//         int u=mindistvertex(dist,sptset);
//         sptset[u]=true;
//         for(int v=0;v<V;v++){
//             if(!sptset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
//                 dist[v]=dist[u]+graph[u][v];
//             }
//         }
//     }
//     printsol(dist);
// }

// void main(){
//     int n;
//     printf("enter number of vertices:");
//     scanf("%d",&n);
//     int path[n][n];
//     printf("enter cost matrix:");
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             scanf("%d",&path[i][j]);
//             if(path[i][j]==0 && i!=j){
//                 path[i][j]=infinity;
//             }
//         }
//     }
//     for(int k=0;k<n;k++){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
//             }
//         }
//     }
//     printf("shortest path matrix:");
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             printf("%d\t",path[i][j]); 
//         }
//         printf("\n");
//     }
// }

// int min(int a,int b){
//     return (a<b) ? a : b;
// }
// int main(){
//     int arr[]={2,5,6,8,23,34,44,59};
//     (bin(arr,23,0,7)!=-1)?printf("found"):printf("not found");
//     return 0;
// }
// int bin(int arr[],int key,int l,int h){
//     int mid=(l+h)/2;
//     while(l<=h){
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if(arr[mid]<key){
//             return bin(arr,key,mid+1,h);
//         }
//         else{
//             return bin(arr,key,l,mid-1);
//         }
//     }
//     return -1;
// }
// void knapsack(int w,struct item items[],int n){
//     double total=0.0,sol[n];
//     int i;
//     for(int i=0;i<n;i++){
//         sol[i]=0.0;
//         items[i].ratio=(double)items[i].profit/items[i].weight;
//         items[i].index=i;
//     }
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(items[i].ratio<items[j].ratio){
//                 struct item temp=items[i];
//                 items[i]=items[j];
//                 items[j]=temp;
//             }
//         }
//     }
//     for(i=0;i<n;i++){
//         if(items[i].weight>w){
//             break;
//         }
//         sol[items[i].index]=1.0;
//         total+=items[i].profit;
//         w-=items[i].weight;
//     }
//     if(i<n){
//         sol[items[i].index]=(double)w/items[i].weight;
//         total+=items[i].profit*sol[items[i].index];
//     }
//     for(int i=0;i<n;i++){
//         printf("%0.2f\t",sol[i]);
//     }
//     printf("\n");
//     printf("total profit: %f",total);
// }
// int main(){
//     struct item items[]={{1,2},{2,3},{5,4}};
//     int w=6,n=3;
//     knapsack(6,items,n);
//     return 0;
// }
int main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct min_max res=find_min_max(arr,0,n-1);
    printf("MINIMUM:%d\nMAXIMUM:%d\n",res.min,res.max);
    return 0;
}
struct min_max find_min_max(int a[],int low,int high){
    struct min_max res,left,right;
    int mid;
    if(low==high){
        res.min=res.max=a[low];
    }
    else if(high==low+1){
        if(a[low]<a[high]){
            res.min=a[low];
            res.max=a[high];
        }
        else{
            res.min=a[high];
            res.max=a[low];
        }
    }
    else{
        mid=low+(high-low)/2;
        left=find_min_max(a,0,mid);
        right=find_min_max(a,mid+1,high);

        //for  min
        if(left.min<right.min){
            res.min=left.min;
        }
        else{
            res.min=right.min;
        }
        //for max
        if(left.max>right.max){
            res.max=left.max;
        }
        else{
            res.max=right.max;
        }
    }
    return res;
}
int knapsack_0_1_(int capacity,int weights[],int values[],int n){
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=capacity;w++){
            if(i==0||w==0){
                dp[i][w]=0;
            }
            else if(weights[i-1]<=w){
                dp[i][w]=max(values[i-1]+dp[i-1][w-weights[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][capacity];
}