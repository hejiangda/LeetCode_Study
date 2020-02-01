// - 实现一个有序数组的二分查找算法
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& v,int x){
    int left=0,right=v.size()-1;
    
    while(left<=right){
        int mid=(left+right)/2;
        if(v[mid]==x)return mid;
        else if(v[mid]>x){
            right=mid-1;
        }
        else if(v[mid]<x){
            left=mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int> demo{9,5,8,2,4,3,7,6,1,0,88,4,5};
    sort(demo.begin(),demo.end());
    cout<<"demo:";
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<binarySearch(demo,0)<<endl;
}