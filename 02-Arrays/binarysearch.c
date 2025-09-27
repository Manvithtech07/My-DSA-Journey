#include<stdio.h>

void binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == target) {
            printf("Element %d found at index %d\n", target, mid);
            return;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element %d not found\n", target);
}

int main() {
    int arr[] = {3, 5, 7, 8, 9, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target_found = 7;
    binarySearch(arr, size, target_found);

    int target_not_found = 10;
    binarySearch(arr, size, target_not_found);

    return 0;
}