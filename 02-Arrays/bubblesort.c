#include<stdio.h>
void bubbleSort(int arr[],int size){
	for(int i=0;i<size-1;i++){
            int swapped = 0;
		for(int j=0;j<size-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=temp;
                swapped = 1;
			}
		}
		if(swapped==0){
            break;//bestcase O(N) array already sorted
		}
	}
}
int main(){
	int arr[] = {5,75,6,3,67,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,size);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
