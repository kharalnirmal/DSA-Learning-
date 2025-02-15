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

void mergeSort(int A[], int l , int h){
    if(l<h){
int mid = (l+h)/2;
mergeSort(A,l,mid);
mergeSort(A,mid+1,h);
merge(A,l,mid,h);
    }
}

int main(){
  int A[]={0,2,4,6,2,7,18,44,56,84,75,};
  int n = 11;

  mergeSort(A,0,n-1);
for (int i = 0; i < n; i++)
{
   
  printf("%d",A[i]);
  printf("\n");

}

}