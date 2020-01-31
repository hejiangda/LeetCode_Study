// - [Missing Positive（求缺失的第一个正数）](https://leetcode-cn.com/problems/first-missing-positive/)

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
 // sort
    // int firstMissingPositive(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     int pos=1;
    //     for(int x:nums){
    //         if(x==pos)
    //             pos++;
    //     }
    //     return pos;
    // }

// unsort
    int firstMissingPositive(vector<int>& nums) {
        int pos=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0 and nums[i]<=n and nums[nums[i]-1]!=nums[i]){
                
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int x:nums){
            if(pos==x)pos++;
        }
        return pos;
    }
};
int main(){
    Solution s;
    vector<int> demo{1,1};
    cout<<s.firstMissingPositive(demo)<<endl;
    return 0;
}