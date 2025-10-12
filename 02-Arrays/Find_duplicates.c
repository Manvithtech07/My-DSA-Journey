//wap to find duplicates in an array
#include<stdio.h>
void findDuplicates(int arr[],int size){
    int found =0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                printf("%d ", arr[i]);
                found = 1;
                break;
            }
        }
    }
    if(found==0){
        printf("No Duplicates");
    }
}
int main(){
    int arr[]={2,4,6,8,2,3,4,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    findDuplicates(arr,size);
    return 0;
}
