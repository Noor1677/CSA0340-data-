#include <stdio.h>
#define MAX_SIZE 100
void findOddEven(int arr[], int size, int* oddNumbers, int* evenNumbers) {
    *oddNumbers = 0;
    *evenNumbers = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            (*evenNumbers)++;
        } else {
            (*oddNumbers)++;
        }
    }
}
int main() {
    int arr[MAX_SIZE];
    int size, oddNumbers, evenNumbers;
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);
    printf("Enter %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    findOddEven(arr, size, &oddNumbers, &evenNumbers);
    printf("Odd numbers: %d\n", oddNumbers);
    printf("Even numbers: %d\n", evenNumbers);
    return 0;
}
