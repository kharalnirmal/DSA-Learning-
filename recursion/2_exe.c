// ^factorial using recursion

int fun (int n){
    if(n==0)
    return 1;
    else{
        return n*fun(n-1);
    }
}
int main(){
    int r;
    r = fun(4);
    printf("%d",r);
    return 0;
}