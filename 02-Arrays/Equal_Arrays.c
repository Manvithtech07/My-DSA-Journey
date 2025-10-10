//check if 2 arrays are equal
#include<stdio.h>
int arrayEqual(int arr1[],int arr2[],int size1,int size2){
    if(size1!=size2){
        return 0;
    }else{
        for(int i=0;i<size1;i++){
            if(arr1[i]!=arr2[i]){
                return 0;
            }
        }
        return 1;
    }
}
int main(){
    int arr1[]={2,3,4,5,6};
    int arr2[]={2,3,4,5,6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    if(arrayEqual(arr1,arr2,size1,size2)){
        printf("Arrays are equal\n");
    }else{
        printf("Not Equal");
    }
    return 0;
}
