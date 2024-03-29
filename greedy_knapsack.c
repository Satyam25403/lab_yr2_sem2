#include<stdio.h>
#include<stdlib.h>
struct item{
    int value;
    int weight;
    double ratio;
    int index;
};
void knapsack(int w,struct item items[],int n);

void knapsack(int w,struct item items[],int n){
    double total=0.0,solution[n];
    int i;
    
    for(i=0;i<n;i++){
        //initialize the solution array with zeroes
        solution[i]=0.0;
        // weight/value ratio for items
        items[i].ratio=(double)items[i].value/items[i].weight;
        //assign indices to items to maintain the order in solution set
        items[i].index=i;
    }

    //(selection)sort items in descending order based on above ratio
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(items[i].ratio<items[j].ratio){
                struct item temp=items[i];
                items[i]=items[j];
                items[j]=temp;
            }
        }
    }

    //fill knapsack greedily
    for(i=0;i<n;i++){
        if(w<items[i].weight){
            break;
        }
        solution[items[i].index]=1.0;
        total+=items[i].value;
        w-=items[i].weight;
    }
    if(i<n){
        solution[items[i].index]=(double)w/items[i].weight;
        total+=items[i].value*solution[items[i].index];
    }

    //display output
    for(i=0;i<n;i++){
        printf("%0.2f\t",solution[i]);
    }
    printf("\n");
    printf("Total profit is: %0.2f",total);
}

int main(){
    struct item items[]={{60,100},{100,20},{120,30},{150,67},{1000,48}};
    int w=50,n=sizeof(items)/sizeof(items[0]);
    knapsack(w,items,n);
    return 0;
}
