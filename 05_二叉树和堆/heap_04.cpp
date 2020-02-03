// - 实现堆排序
#include <bits/stdc++.h>

using namespace std;

void HeapSort(vector<int>& v){
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<v.size();i++){
        q.push(v[i]);
    }
    for(int i=0;i<v.size();i++){
        v[i]=q.top();
        q.pop();
    }
}
int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    HeapSort(demo);
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}