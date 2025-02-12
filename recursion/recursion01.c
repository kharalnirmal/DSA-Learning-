// #include<stdio.h>

void func1(int n){
    if(n>0){

        //  !note when there is tail recursion the print statement is executed before the recursive call - acending
    // !note when there is head recursion the print statement is executed after the recursive call - decending 
        func1(n-1);
        printf("%d",n);
    }
}
int main(){

    int x =4 ; 
    func1(x);
    return 0;
}