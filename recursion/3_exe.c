//^ exponent using recursion

#include<stdio.h>

int power(int base,int exp){
    if(exp==0){
        return 1;
    }
    else{
        return base*power(base,exp-1);
    }
}
int main(){
    int base , exponent;
    printf("Enter the base : ",base);
    scanf("%d",&base);
    printf("Enter the exponent : ",exponent);
    scanf("%d",&exponent);
    printf("%d to the power %d  is %d: ",base,exponent,power(base,exponent));
    return 0;
}