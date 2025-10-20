//Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.
#include<stdio.h>
#include<limits.h>
int secondLargest(int arr[],int size){
    if(size<2) return -1;
    int largest = arr[0];
    int second = INT_MIN;
    for(int i=1;i<size;i++){
        if(arr[i]>largest){
            second = largest;
            largest = arr[i];
        }else if (arr[i]<largest && arr[i]>second){
            second = arr[i];
        }
    }
    if(second == INT_MIN) return -1;
        return second;
}
int main(){
    int arr[]={3,3,99,23,-40};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = secondLargest(arr,size);
    printf("%d ",result);
    return 0;
}
