// - 编程实现斐波那契数列求值 f(n)=f(n-1)+f(n-2)
#include <bits/stdc++.h>

using namespace std;
int f(int n){
    if(n<=2)
        return 1;
    else{
        return f(n-1)+f(n-2);
    }
}
int fn(int n){
    int f1=1;
    int f2=1;
    if(n<=2)
        return 1;
    else{
        int fnn;
        for(int i=2;i<n;i++){
            fnn=f1+f2;
            f1=f2;
            f2=fnn;
        }
        return fnn;
    }
    
}
int main(){
    cout<<"Fib1:";
    for(int i=1;i<10;i++){
        cout<<f(i)<<" ";
    }
    cout<<endl;
    cout<<"Fib2:";
    for(int i=1;i<10;i++){
        cout<<fn(i)<<" ";
    }
    cout<<endl;
    return 0;
}