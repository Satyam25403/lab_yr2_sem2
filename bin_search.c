#include<stdio.h>
int bin(int a[],int data,int l,int r);
int main(){
    int arr[]={-4,3,4,7,45,56,78,98};
    int index=bin(arr,45,0,7);
    if(index==-1){
        printf("\n element not found");
    }
    else{
        printf("\nelement present at position:%d",index+1);
    }
    return 0;
}
int bin(int a[],int data,int l,int r){
    int mid=(l+r)/2;
    while(l<=r){
        if(data==a[mid]){
            return mid;
        }
        else if(data<a[mid]){
            return bin(a,data,l,mid-1);
        }
        else{
            return bin(a,data,mid+1,r);
        }
    }
    return -1;
}
