#include <stdio.h>

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[100]; // Temporary array

    // Merge the two halves
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // Copy remaining elements from left subarray
    for (; i <= mid; i++)
        B[k++] = A[i];

    // Copy remaining elements from right subarray
    for (; j <= h; j++)
        B[k++] = A[j];

    // Copy back to original array
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void ImergeSort(int A[], int n) {
    int p, i, l, mid, h;
    for (p = 2; p <= n; p *= 2) {
        for (i = 0; i + p - 1 < n; i += p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }

    // Merge remaining elements if array size is not a power of 2
    if (p / 2 < n) {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}

int main() {
    int A[] = {9, 8, 7, 6, 5, 99, 3, 32, 33};
    int n = sizeof(A) / sizeof(A[0]);

    ImergeSort(A, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
