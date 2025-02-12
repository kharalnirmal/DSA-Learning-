#include <stdio.h>

int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble(int A[], int n)
{
    int i, j;
    int flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            };
        };
        if (flag == 0)
            break;
    };
};

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}, n = 9;
    Bubble(A,9);
    for (int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
        printf("\n");
    }

    return 0;
};