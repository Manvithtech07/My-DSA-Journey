//check if palindrome or not
#include<stdio.h>
int isPalindrome(int arr[],int size){
    for(int i=0;i<size/2;i++){
        if(arr[i]!=arr[size-1-i]){
            return 0; //Not palindrome
        }
        return 1;//isPalindrome
    }
}
int main(){
    int arr[]={1,2,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    if(isPalindrome(arr,size)){
        printf("Palindrome\n");
    }else{
        printf("Not a palindrome\n");
    }
    return 0;
}
