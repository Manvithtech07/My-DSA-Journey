#include<stdio.h>
int LinearSearch(int arr[], int size, int target){
	for(int i=0;i<size;i++){
		if(arr[i]==target){
			printf("Element %d found at index %d\n",target,i);
		}
	}
	printf("Element not in list\n");
}
int main(){
	int arr[]={2,1,5,7,34,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	int target = 8;
	LinearSearch(arr,size,target);
	return 0;
}