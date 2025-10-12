//case1 -Input: nums = [2,7,11,15], target = 9 Output: [0,1]
#include<stdio.h>
void TwoSum(int arr[],int size,int target){
    int found = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==target){
                printf("%d,%d",i,j);
                found = 1;
                return;
            }
        }
    }
    if(found == 0){
        printf("No two elements sum up to the target.\n");
    }
}
int main(){
    int arr[]={2,7,11,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 9;
    TwoSum(arr,size,target);
    return 0;
}

