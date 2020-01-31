#include <bits/stdc++.h>
using namespace std;
// 双指针法

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ret;
        if(n<3)return ret;
        for(int l=0;l<n;l++){
            if(nums[l]>0)return ret;
            if(l>0 and nums[l]==nums[l-1])
                continue;
            int m=l+1;
            int r=n-1;
            while(m<r){
                int sum=nums[l]+nums[m]+nums[r];
                if(sum<0){
                    m++;
                }
                else if(sum==0){
                    ret.push_back(vector<int>{nums[l],nums[m],nums[r]});
                    while(r>0 and nums[r]==nums[r-1])
                        r--;
                    r--;
                    while(m<n-1 and nums[m]==nums[m+1])
                        m++;
                    m++;
                }
                else {
                    r--;
                }
            
            }
        }
        return ret;
    }
};

/**
 * [-4 -1 -1 0 1 2 ]
 *   -2,0,1,1,2
 * -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6
 * [-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0]
 * -1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3
 * */
int main(){
    vector<int> example{-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};
    vector<vector<int>> result;
    Solution s;
    result=s.threeSum(example);
    for(auto v:result){
        cout<<"[";
        for(auto x:v){
            cout<<" "<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"demo:{";
    for(auto x:example){
        cout<<" "<<x<<" ";
    }
    cout<<"}"<<endl;
    return 0;
}
