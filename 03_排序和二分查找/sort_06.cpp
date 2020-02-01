// - 编程实现 O(n) 时间复杂度内找到一组数据的第 K 大元素
#include <bits/stdc++.h>

using namespace std;

int Foo(vector<int>& v,int k,int left,int right){
    if(left>=right)
        return left;
    swap(v[left],v[right]);
    int storedIndex=left;
    for(int i=left+1;i<right;i++){
        if(v[i]>v[right]){
            swap(v[i],v[storedIndex++]);
        }
    }
    swap(v[right],v[storedIndex]);
    return storedIndex;
}

int findKth(vector<int> v,int k){
    int left=0,right=v.size()-1;
    
    int res=Foo(v,k-1,left,right);
    while(res!=k-1){
        if(res>k-1){
            res=Foo(v,k-1,left,res-1);
        }else{
            res=Foo(v,k-1,res+1,right);
        }
    }
    return v[k-1];
}

int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    cout<<findKth(demo,5)<<endl;
    return 0;
}