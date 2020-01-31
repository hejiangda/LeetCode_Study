// - 实现归并排序、快速排序、插入排序、冒泡排序、选择排序
// 选择排序
#include <bits/stdc++.h>

using namespace std;
void selectSort(vector<int>& v){
    int n=v.size();
    for(int i=0;i<n;i++){
        int x=i;
        for(int j=i;j<n;j++){
            if(v[j]<v[x]){
                x=j;
            }
        }
        swap(v[x],v[i]);
    }
}

int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    selectSort(demo);
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}