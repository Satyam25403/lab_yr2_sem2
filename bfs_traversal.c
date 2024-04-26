//works good
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int q[MAX],front=-1,rear=-1,visit[MAX],g[MAX][MAX],n;

int is_full();
int is_empty();
void enqueue(int a);
int dequeue();


int main(){
    int i,j,v,n,s,w;
    printf("\n BFS using arrays:");
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    if(n<1 || n>MAX){
        printf("Invalid input. Number of vertices should be between 1 and %d.\n",MAX);
        exit(1);
    }
    //initially no vertex is visited
    for(i=0;i<n;i++){
        visit[i]=0;
    }

    printf("\nAdjacency Matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    printf("Enter starting vertex:");
    scanf("%d",&s);
    if(s<1 || s>n){
        printf("Invalid input. Starting vertex should be between 1 and %d.\n",n);
        exit(1);
    }
    printf("\nBFS order:");
    for(i=0;i<n;i++){
        q[i]=0;
    }
    enqueue(s-1);
    visit[s-1]=1;
    printf("%d\t",s);

    while(!is_empty()){
        v=dequeue();
        for(w=0;w<n;w++){
            //if vertex is adjacent and is not visited till now
            if(g[v][w]==1 && visit[w]!=1){
                visit[w]=1;
                printf("%d\t",w+1);
                enqueue(w);
            }
        }
    }
    printf("\n");
}
void enqueue(int a){
    if(is_full()){
        printf("queue is full");
    }
    if(front==-1){
        front=0;
    }
    q[++rear]=a;
}
int dequeue(){
    int n;
    if(is_empty()){
        printf("underflow");
    }
    if(front==rear){
        n=q[front];
        front=rear=-1;
    }
    else{
        n=q[front++];
    }
    return n;
}
int is_empty(){
    return (front==-1 || front>rear);
}
int is_full(){
    return rear==MAX-1;
}

