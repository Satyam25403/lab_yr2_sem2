//works good
#include<stdio.h>
struct min_max{
    int min;
    int max;
};
struct min_max find_min_max(int a[],int low,int high);
int main(){
    int n;
    printf("\nEnter the number of elements in the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements in the array:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    struct min_max res=find_min_max(a,0,n-1);
    printf("MAXIMUM=%d\tMINIMUM=%d\t",res.max,res.min);
    return 0;
}
struct min_max find_min_max(int a[],int low,int high){
    struct min_max result,left,right;       //initialize two structure variables
    int mid;

    //only one element present
    if(low==high){
        result.min=result.max=a[low];
    }

    //two elements present
    else if(high==low+1){
        if(a[low]<a[high]){
            result.min=a[low];
            result.max=a[high];
        }
        else{
            result.min=a[high];
            result.max=a[low];
        }
    }

    //more than two elements
    else{
        mid=(high+low)/2;
        left=find_min_max(a,low,mid);
        right=find_min_max(a,mid+1,high);

        //compare mins and maxs of two halves
        //for min
        if(left.min<right.min){
            result.min=left.min;
        }
        else{
            result.min=right.min;
        }
        //for max
        if(left.max>right.max){
            result.max=left.max;
        }
        else{
            result.max=right.max;
        }
    }
    return result;
}

