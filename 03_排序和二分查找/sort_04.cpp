// - 实现归并排序、快速排序、插入排序、冒泡排序、选择排序
// 快速排序
#include <bits/stdc++.h>

using namespace std;
void st(vector<int>& v,int front,int end)
{
    if(front>=end)
        return;
    swap(v[front],v[end]);
    int i=front;
    int store=front;
    for(int i=front;i<end;i++){
        if(v[i]<=v[end]){
            swap(v[store++],v[i]);
        }
    }
    swap(v[store],v[end]);
    st(v,front,store-1);
    st(v,store+1,end);
}
void st1(vector<int>& v,int front,int end){
    if(front>=end)
        return;
    swap(v[front],v[end]);
    int left=front;
    int right=end-1;
    while(left<right){
        while(left<right and v[left]<v[end])
            left++;
        while(left<right and v[right]>=v[end])
            right--;
        swap(v[left],v[right]);
    }
    if(v[left]>=v[end]){
        swap(v[left],v[end]);
    }else {
        swap(v[++left],v[end]);
    }
    st1(v,front,left-1);
    st1(v,left+1,end);
}
void quickSort(vector<int>& v){
    st1(v,0,v.size()-1);
}

int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    quickSort(demo);
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}