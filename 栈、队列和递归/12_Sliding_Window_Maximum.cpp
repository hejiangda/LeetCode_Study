// - [Sliding Window Maximum（滑动窗口最大值）](https://leetcode-cn.com/problems/sliding-window-maximum/)
#include <bits/stdc++.h>

using namespace std;
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ret;
//         int n=nums.size();
//         if(k<=0)return ret;
//         for(int i=0;i<n-k+1;i++){
//             int maxnum=nums[i];
//             for(int j=i+1;j<i+k;j++){
//                 if(nums[j]>maxnum)
//                     maxnum=nums[j];
//             }
//             ret.push_back(maxnum);
//         }
//         return ret;
//     }
// };
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if(k<=0)return ret;
        deque<int> dq;
        int n=nums.size();
        for(int i=0;i<k;i++){
            
            while(dq.size()>0 and nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ret.push_back(nums[dq.front()]);
        
        for(int i=k;i<n;i++){
            while(dq.size()>0 and dq.front()<=i-k){
                dq.pop_front();
            }
            
            while(dq.size()>0 and nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};
int main(){
    Solution s;
    vector<int> example{1,3,1,2,0,5};
    vector<int>x=s.maxSlidingWindow(example,3);
    for(int y:x){
        cout<<y<<" ";
    }
    cout<<endl;

    return 0;
}