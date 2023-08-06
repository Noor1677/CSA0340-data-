#include <stdio.h>
long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input. Number of terms must be greater than 0.\n");
        return 1; 
    }
    printf("Fibonacci Series: ");
    for (i = 0; i < n; ++i) {
        printf("%lld, ", fibonacci(i));
    }
    return 0;
}
