#include<stdio.h>
#include<stdlib.h>
int Find_Max(int A[], int n){
    int max = 0 ;
    for ( int i=0 ; i<n ; i++){
        if(A[i]>max){
        max = A[i];
    };
   
    };
    return max;
    
}

void CountSort(int A[],int n){
    int max;
    int *c;
    max = Find_Max(A,n);
    c = (int *) malloc(sizeof(int)*(max+1));
    for(int i = 0; i<max+1;i++){
        c[i]=0;
    };
    for(int i= 0 ; i<n;i++){
        c[A[i]]++;
    };
    int i= 0 ; int j= 0;
    while(i<max+1){
        if(c[i]>0){
            A[j++] = i;
            c[i]--;

        }
        else{
            i++;
        };
    };
};


int main (){
    int A[]={99,33,44,5,66,7,3,1,95,34,56,75,43,32,21,12}, n= 16;
    CountSort(A,16);
    for (int i = 0; i < 10; i++){
    printf("%d ", A[i]);
printf("\n");}

return 0;

}