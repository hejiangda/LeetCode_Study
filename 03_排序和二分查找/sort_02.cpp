// - 实现归并排序、快速排序、插入排序、冒泡排序、选择排序
// 冒泡排序
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& v){
    
    for(int i=0;i<v.size();i++){
    bool flg=true;
        for(int j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                flg=false;
            }
        }
        if(flg)break;
    }
}
int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    bubbleSort(demo);
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}