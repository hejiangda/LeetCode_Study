// - 实现归并排序、快速排序、插入排序、冒泡排序、选择排序
// 实现归并排序
#include <bits/stdc++.h>

using namespace std;
void Merge(vector<int>&v,int*tmp,int l1,int r1,int l2,int r2){
    int left=l1,right=r2;
    int p=l1;
    while(l1<=r1 and l2<=r2){
        if(v[l1]<v[l2]){
            tmp[p++]=v[l1++];
        }else tmp[p++]=v[l2++];
    }
    while(l1<=r1){
        tmp[p++]=v[l1++];
    }
    while(l2<=r2){
        tmp[p++]=v[l2++];
    }
    for(int i=left;i<=right;i++){
        v[i]=tmp[i];
    }
}
void Sort(vector<int>&v,int *tmp,int left,int right){
    if(left>=right)
        return;
    int mid=(left+right)/2;
    Sort(v,tmp,left,mid);
    Sort(v,tmp,mid+1,right);
    Merge(v,tmp,left,mid,mid+1,right);
}
void mergeSort(vector<int>& v){
    int* tmp=new int[v.size()];
    Sort(v,tmp,0,v.size()-1);
    delete tmp;
}

int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    mergeSort(demo);
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}