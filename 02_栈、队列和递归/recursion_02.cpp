// - 编程实现求阶乘 n!
#include <bits/stdc++.h>

using namespace std;
int f(int n){
    if(n<=1){
        return 1;
    }else{
        return n*f(n-1);
    }
}
int main(){
    for(int i=0;i<10;i++){
        cout<<f(i)<<" ";
    }
    cout<<endl;
    return 0;
}