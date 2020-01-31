// - 实现归并排序、快速排序、插入排序、冒泡排序、选择排序
// 插入排序
#include <bits/stdc++.h>

using namespace std;

void insertSort(vector<int>& v){
    for(int i=1;i<v.size();i++){
        int x=v[i];
        int j=i-1;
        while(x<v[j] and j>=0){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=x;
    }
}
int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    insertSort(demo);
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}