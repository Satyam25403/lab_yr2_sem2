//works good
#include<stdio.h>
struct job{
    int id;
    int deadline;
    int profit;
};
void sort(struct job arr[],int n);
int max_deadline(struct job arr[],int n);
void job_sequence(struct job arr[],int n);

int main(){
    struct job arr[]={{1,2,50},{2,1,15},{3,2,10},{4,1,25}};
    int n=sizeof(arr)/sizeof(arr[0]);
    job_sequence(arr,n);
    return 0;
}
void sort(struct job arr[],int n){
    //implement bubble sort on structures in descending order of profits
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].profit<arr[j+1].profit){
                struct job temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//make an array of size equal to the maximum deadline
int max_deadline(struct job arr[],int n){
    int maxDeadline=0;
    for(int i=0;i<n;i++){
        if(arr[i].deadline>maxDeadline){
            maxDeadline=arr[i].deadline;
        }
    }
    return maxDeadline;
}
void job_sequence(struct job arr[],int n){
    //sort jobs based on profits
    sort(arr,n);

    //initialize job sequence array
    int maxDeadline=max_deadline(arr,n);
    int sequence[maxDeadline];
    //initialize slots to -1
    for(int i=0;i<maxDeadline;i++){
        sequence[i]=-1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        //for each job in the sorted list of jobs
        for(int j=arr[i].deadline-1;j>=0;j--){
            if(sequence[j]==-1){
                sequence[j]=arr[i].id;
                sum+=arr[i].profit;
                //since this job found its slot break and move to next job
                break;
            }
        }
    }
    printf("\n Sequence of jobs:");
    for(int i=0;i<maxDeadline;i++){
        //avoid printing un-initialized slots
        if(sequence[i] != -1) {
            printf("%d\t", sequence[i]);
        }
    }
    printf("\n");
    printf("maximum profit:%d",sum);
}