#include <stdio.h>

void shellSort(int A[], int n) {
    int gap, i, j;
    for (gap = n / 2; gap >= 1; gap /= 2) {  // Reduce gap size
        for (i = gap; i < n; i++) {  // Start sorting elements with the given gap
            int temp = A[i];  
            j = i - gap;
            while (j >= 0 && A[j] > temp) {  // Move elements if they are greater
                A[j + gap] = A[j];  
                j -= gap;
            }
            A[j + gap] = temp;  // Place temp in the correct position
        }
    }
}

int main() {
    int A[] = {3, 5, 6, 7, 9, 23, 11};  // Corrected array size
    int n = 7;  // Correct size
    shellSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
