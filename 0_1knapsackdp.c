//update the program to print the boolean solution set
#include<stdio.h>
int max(int, int );
int knapsack(int capacity,int weights[],int values[],int n);

int main(){
    int n,capacity;
    printf("Enter number of items:");
    scanf("%d",&n);
    printf("Enter capacity of knapsack:");
    scanf("%d",&capacity);
    int values[n],weights[n];
    printf("enter profits and weights for the items:\n\n");
    for(int i=0;i<n;i++){
        printf("profit and weight for item-%d : ",i+1);
        scanf("%d%d",&values[i],&weights[i]);
    }
    printf("Maximum value :%d\n",knapsack(capacity,weights,values,n));
    return 0;
}
int max(int a,int b){
    return a>b?a:b;
}
int knapsack(int capacity,int weights[],int values[],int n){
    //2-d array to store the max value that can be obtained with current combination of items and capacities
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=capacity;w++){
            //base case :when there are no items(i) or the capacity(w) is 0
            if(i==0||w==0){
                dp[i][w]=0;
            }
            //if current item's weight is less than or equal to current capacity, consider whether to include or not
            else if(weights[i-1]<=w){
                dp[i][w]=max(values[i-1]+dp[i-1][w-weights[i-1]],dp[i-1][w]);
            }
            //if current items weight is more than the current capacity, then exclude and take value from the previous row
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    //return the max value obtained from the bottom right cell of the dp table
    return dp[n][capacity];
}
