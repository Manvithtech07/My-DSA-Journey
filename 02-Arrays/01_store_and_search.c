/*Q1. Define data structure. Write a program to store element in an array of size 10 by calling the function create_array(int *). Write a function to search an element in an array.*/

/*Ans: Data structure is a systematic way of organizing and storing data in a computers memory so that it can be accessed and maniplulated efficiently.       
 						Data Structure

Primitive data structure 						Compound Data structure
-int										  linear ds      nonlinear ds
-float										  -array		 -tree
-char								  		  -linkedlist    -graph
-pointer									  -stack		 -files
											  -queue
											  */
#include<stdio.h>
#define SIZE 10
void create_array(int *arr){
	printf("Enter 10 elements:\n");
	for(int i=0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}
}
void search_element(int *arr, int key){
	int found = 0;
	for(int i=0;i<SIZE;i++){
		if(arr[i]==key){
			printf("Element %d found at index %d\n",key,i);
			found = 1;
			break;
		}
	}
	if(found==0){
		printf("Element %d was not found",key);
	}
}
int main(){
	int my_arr[SIZE];
	int search_value;
	create_array(my_arr);
	printf("Enter the element you want to seach:\n");
	scanf("%d",&search_value);
	search_element(my_arr,search_value);
	return 0;
}