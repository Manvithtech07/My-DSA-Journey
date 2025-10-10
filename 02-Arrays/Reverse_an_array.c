//Reverse an array
#include<stdio.h>
void Reversed(int arr[],int size){
    for(int i=0;i<size/2;i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i]=temp;
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    Reversed(arr,size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
