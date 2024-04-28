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
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);

    //initially no vertex is visited
    for(i=0;i<n;i++){
        visit[i]=0;
    }

    printf("\n Enter Adjacency Matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    printf("Enter starting vertex:");
    scanf("%d",&s);

    printf("\nBFS order:");
    //initialize an empty queue
    for(i=0;i<n;i++){
        q[i]=0;
    }
    enqueue(s-1);
    visit[s-1]=1;
    printf("%d\t",s);

    while(!is_empty()){
        v=dequeue();
        //for the dequeued vertex, traverse all its adjacent vertices
        for(w=0;w<n;w++){
            //if vertex is adjacent and is not visited till now
            if(g[v][w]==1 && visit[w]!=1){
                visit[w]=1;
                printf("%d\t",w+1);//actual vertex to be printed is w 1 is added as numbering starts from 1
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
        //only one element there
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

