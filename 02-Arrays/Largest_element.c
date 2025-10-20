//Given an array of integers nums, return the value of the largest element in the array
#include<stdio.h>
int largestElement(int arr[],int size){
    int largest = arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}
int main(){
    int arr[]={3, 3, 6, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = largestElement(arr,size);
    printf("%d ",result);
    return 0;
}

