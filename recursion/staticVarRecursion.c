//  ^ without static variable

// int func(int x){
//     if(x>0){
//         return func(x-1)+x;
//     }
//     return 0;
// }

// int main(){
//     int x = 5;
//     printf("%d\n",func(x));
//     return 0;
// }

//^ with static variable

#include<stdio.h>

int  func ( int n ){
    static int x = 6;
    if(n>0){
x++;
return func(n-1)+x;
    }}

    int  main (){
        int a = 5 ;
        printf("%d\n",func(a));

        return 0;
    }