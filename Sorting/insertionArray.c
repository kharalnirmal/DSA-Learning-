void insertion(int A[],int n){
    int i, j,x ;
    for(i=1; i<n;i++){
        j=i-1;
        x=A[i];
        while (j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
        
    }

}

int main(){
    int A[] = {9,8,7,6,5,4,3,2,1,10};
    insertion(A,10);
    for(int i=0; i<10 ; i++){
        printf("%d\n",A[i]);
    }

}