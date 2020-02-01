// - 实现模糊二分查找算法（比如大于等于给定值的第一个元素）
#include <bits/stdc++.h>

using namespace std;

int blurBinarySearch(vector<int>& v,int x){
    int left=0,right=v.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(v[mid]>=x){
            if(mid>0 and v[mid-1]>=x){
                right=mid-1;
            }else return mid;
        }else{
            left=mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int> demo{9,5,8,2,4,7,6,1,0,88,4,5};
    sort(demo.begin(),demo.end());
    for(int x:demo){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<blurBinarySearch(demo,3)<<endl;
    return 0;
}