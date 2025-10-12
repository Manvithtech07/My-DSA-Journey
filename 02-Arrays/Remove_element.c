//wap to remove a specific element from an array
#include<stdio.h>
void Remove_ele(int arr[],int size){
    int n;
    printf("Enter the element to remove:\n");
    scanf("%d",&n);
    int pos = -1;
    for(int i=0;i<size;i++){
        if(arr[i]==n){
            pos = i;
            break;
        }
    }
    if(pos==-1){
        printf("\nElement not found");
        return;
    }
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }size--;
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]={2,4,5,6,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    Remove_ele(arr,size);
    return 0;
}
