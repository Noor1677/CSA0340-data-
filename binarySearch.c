#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int size, target;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &target);
    int index = binarySearch(arr, size, target);
    if (index != -1) {
        printf("Number %d found at index %d\n", target, index);
    } else {
        printf("Number %d not found in the array.\n", target);
    }
    return 0;
}
