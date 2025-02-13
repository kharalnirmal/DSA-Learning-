#include <stdio.h>

int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}




void selectionSort(int A[],int n){
    int i,j,k;
    for (i=0;i<n-1;i++){
        for (j=k=i;j<n;j++){
            if(A[j]<A[k]){
             k=j;
            };
        };
        swap(&A[i],&A[k]);
    };
};

int main()
{
    int A[] = {9, 8, 7, 6, 522, 4, 3, 2, 1}, n = 9;
selectionSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
        printf("\n");
    }

    return 0;
};