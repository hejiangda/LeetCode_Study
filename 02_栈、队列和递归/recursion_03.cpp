// - 编程实现一组数据集合的全排列
#include <bits/stdc++.h>
/**
 * 1 2 3
 * 1 3 2
 * 2 3 1
 * 2 1 3
 * 3 1 2 
 * 3 2 1
 * 
 * 1
 * 
 * 1 2
 * 2 1
 * 
 */
//f({a,b,c})=a+f{b,c},b+f{a,c},c+f(a,b);
//f{b,c}=b+f(c),c+f(b);
/**
 * 确定首位
 * 确定第二位
 * 确定。。。
 * 
*/
using namespace std;
void ff(int* d,int* h,int sz,int pos);
void f(int n){
    int demo[n+1];
    int hs[n+1]={0};
    ff(demo,hs,n,0);
}
void ff(int* d,int* h,int sz,int pos){
    if(pos==sz){
        for(int i=0;i<sz;i++){
            cout<<d[i]<<" ";
        }
        cout<<endl;
    }else{
        for(int i=1;i<=sz;i++){
            if(h[i]==0){
                d[pos]=i;
                h[i]=1;
                ff(d,h,sz,pos+1);
                h[i]=0;
            }
        }
    }
}
int main(){
    f(1);
    f(2);
    f(3);
    return 0;
}