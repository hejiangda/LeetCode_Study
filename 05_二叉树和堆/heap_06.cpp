// - 求一组动态数据集合的最大 Top K
#include <bits/stdc++.h>

using namespace std;
vector<int> TopK(vector<int>& v,int k){
    vector<int> ret;
    priority_queue<int> q;
    for(int x:v){
        q.push(x);
    }
    for(int i=0;i<k;i++){
        ret.push_back(q.top());
        q.pop();
    }
    return ret;
}
int main(){
    vector<int> demo{1,5,8,7,10,3,2,9,6};
    vector<int> ret=TopK(demo,4);
    cout<<"TopK:";
    for(int x:ret){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}