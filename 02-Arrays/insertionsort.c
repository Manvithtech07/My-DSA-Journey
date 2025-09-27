#include<stdio.h>
void insertionSort(int arr[],int size){
	for(int i=0;i<=size-1;i++){
		int j=i;
		while(j>0 && arr[j-1]>arr[j]){
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}
int main(){
	int arr[]={4,2,5,7,1,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr,size);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}