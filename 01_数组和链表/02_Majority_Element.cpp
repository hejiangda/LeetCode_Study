//- [Majority Element（求众数）](https://leetcode-cn.com/problems/majority-element/)
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
// hash solution
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for(int x:nums){
    //         mp[x]++;
    //     }
    //     int maxcnt=0;
    //     int maxnum;
    //     for(auto x:mp){
    //         if(x.second>maxcnt){
    //             maxcnt=x.second;
    //             maxnum=x.first;
    //         }
    //     }
    //     return maxnum;
    // }
// count
    int majorityElement(vector<int>& nums) {
        int maj;
        int cnt=0;
        for(int x:nums){
            if(cnt==0)
                maj=x;
            if(x==maj)
                cnt++;
            else cnt--;
        }
        return maj;
    }
};
int main(){
    vector<int> demo{2,2,1,1,1,2,2};
    Solution s;
    cout<<s.majorityElement(demo)<<endl;

    return 0;
}
