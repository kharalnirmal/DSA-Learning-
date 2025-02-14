# Iterative Merge Sort in C

This document provides a detailed breakdown of the iterative merge sort program in C, explaining every part of the code and the logic behind it.

---

## **Program Overview**
Merge Sort is a divide-and-conquer sorting algorithm that splits the array into smaller parts, sorts them, and then merges them back. The iterative approach avoids recursion by progressively merging subarrays of increasing size.

---

## **Code Breakdown**

### **1. Header File**
```c
#include <stdio.h>
```
- `#include <stdio.h>`: This includes the standard input-output library, allowing us to use `printf()` and other I/O functions.

---

### **2. Merge Function**
```c
void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[100]; // Temporary array
```
- `int i = l, j = mid + 1, k = l;` → Initializes pointers:
  - `i` starts at `l` (left subarray)
  - `j` starts at `mid + 1` (right subarray)
  - `k` is used to index into the temporary array `B[]`.
- `int B[100];` → Temporary array to store the sorted elements.

#### **Merging Two Sorted Halves**
```c
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
```
- Compares elements from both halves (`A[i]` and `A[j]`).
- The smaller element is copied to `B[k]` and pointers are updated.
- This ensures sorted merging.

#### **Copy Remaining Elements from Left Subarray**
```c
    for (; i <= mid; i++)
        B[k++] = A[i];
```
- If elements remain in the left subarray, they are copied to `B`.

#### **Copy Remaining Elements from Right Subarray**
```c
    for (; j <= h; j++)
        B[k++] = A[j];
```
- If elements remain in the right subarray, they are copied to `B`.

#### **Copy Back to Original Array**
```c
    for (i = l; i <= h; i++)
        A[i] = B[i];
}
```
- The sorted elements from `B[]` are copied back to `A[]`, ensuring the original array is updated.

---

### **3. Iterative Merge Sort Function**
```c
void ImergeSort(int A[], int n) {
    int p, i, l, mid, h;
```
- `p`: Defines the size of the subarrays being merged.
- `i`: Loop variable for iteration.
- `l`, `mid`, `h`: Define the left, middle, and right indices of the subarrays.

#### **Iterative Merging of Subarrays**
```c
    for (p = 2; p <= n; p *= 2) {
        for (i = 0; i + p - 1 < n; i += p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
```
- `p` starts at `2` and doubles each iteration (`p *= 2`), defining the size of subarrays to merge.
- The inner loop processes `p`-sized subarrays until the entire array is sorted.
- `merge(A, l, mid, h);` merges the subarrays at each step.

#### **Final Merge for Remaining Elements**
```c
    if (p / 2 < n) {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}
```
- If the array size is not a perfect power of 2, this final step merges the remaining elements.

---

### **4. Main Function**
```c
int main() {
    int A[] = {9, 8, 7, 6, 5, 99, 3, 32, 33};
    int n = sizeof(A) / sizeof(A[0]);
```
- Initializes an unsorted array `A[]`.
- `sizeof(A) / sizeof(A[0])` calculates the number of elements (`n`).

#### **Calling Merge Sort and Printing the Sorted Array**
```c
    ImergeSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
```
- Calls `ImergeSort(A, n);` to sort the array.
- Prints the sorted array using a loop.

---

## **How the Algorithm Works**
### **Step-by-Step Execution**
1. The array is broken into pairs (`p = 2`), and adjacent elements are merged.
2. The subarray size doubles (`p = 4`), and 4-element subarrays are merged.
3. This continues until the entire array is sorted.

### **Example Execution**
#### **Input:**
```c
A[] = {9, 8, 7, 6, 5, 99, 3, 32, 33}
```
#### **Sorting Process:**
1. Merge pairs → `{8,9} {6,7} {5,99} {3,32} {33}`
2. Merge 4-element subarrays → `{6,7,8,9} {3,5,32,99} {33}`
3. Final merge → `{3,5,6,7,8,9,32,33,99}`

#### **Output:**
```c
3 5 6 7 8 9 32 33 99
```

---

## **Time Complexity Analysis**
| Case       | Complexity |
|------------|------------|
| Best Case  | O(n log n) |
| Worst Case | O(n log n) |
| Average Case | O(n log n) |

- **Space Complexity:** O(n) due to the temporary array `B[]`.
- **Advantage:** Avoids recursion stack overhead compared to recursive merge sort.

---

## **Conclusion**
This iterative merge sort efficiently sorts an array without recursion. The approach merges subarrays iteratively, doubling their size each time until the entire array is sorted. The algorithm runs in `O(n log n)` time and is well-suited for large datasets.

