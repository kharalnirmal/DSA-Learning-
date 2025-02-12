//&   Recursion with simple approach


// #include<stdio.h>

//  int e(int x, int n){
//     static int p=1, f=1;
//     int r ;
//     if(n==0){
//         return 1;
//     }
//     else{
//         r=e(x,n-1);
//         p= p*x;
//         f=f*n;
//         return r+p/f;
//     }
//  }

//  int main(){
//     int r = e(2,3);
//     printf("%d",r);
//     return 0;
//  }


//&   Recursion with Horner's Rule

#include<stdio.h>
double e(int x , int n){
    static double s=1;
    if(n==0){
        return s;
    }
    s=1+x/n*s;
    return e(x , n-1);
}

int main(){
   double r= e(3,2);
   printf("%lf ",r);
   return 0;
}