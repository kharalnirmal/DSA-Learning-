//^ sum of first n natural number using recursion
#include <stdio.h>

int fun(int n) {
    if (n == 0)
        return 0;
    else
        return n + fun(n - 1);
}

int main() {
    int n;
    printf("Enter the natural number: ");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers is: %d\n", n, fun(n));
    return 0;
}