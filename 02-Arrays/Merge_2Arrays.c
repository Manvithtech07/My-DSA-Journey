//Merge 2 sprted arrays and the new array should also be sorted
#include<stdio.h>
void mergearrays(int arr1[],int arr2[],int size1, int size2){
    int merged[100];int i=0,j=0,k=0;
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            merged[k++]=arr1[i++];
        }else{
            merged[k++]=arr2[j++];
        }
    }
    while(i<size1) merged[k++]=arr1[i++];
    while(j<size2) merged[k++]=arr2[j++];
    for(int x=0;x<k;x++){
        printf("%d ",merged[x]);
    }
}
int main(){
    int arr1[]={2,4,6,8,10,12};
    int arr2[]={1,3,5,7,9};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    mergearrays(arr1,arr2,size1,size2);
    return 0;
}
