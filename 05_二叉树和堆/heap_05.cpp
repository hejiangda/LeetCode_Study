// - 利用优先级队列合并 K 个有序数组
#include <bits/stdc++.h>

using namespace std;
vector<int>& Merge(vector<vector<int>>& v){
    vector<int>* ret=new vector<int>;
    priority_queue<int,vector<int>,greater<int>> q;
    for(vector<int> tmp:v){
        for(int x:tmp){
            q.push(x);
        }
    }
    while(!q.empty()){
        ret->push_back(q.top());
        q.pop();
    }
    return *ret;
}
int main(){
    vector<vector<int>>demo={{1,2,3,4,5},{-5,-6,6,8,9,10},{7}};
    vector<int> v=Merge(demo);
    cout<<"after merge:";
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}