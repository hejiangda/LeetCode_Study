/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            while(nums[i]>0 and nums[i]<=nums.size() and nums[i]!=i+1 and nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int i=1;
        for(;i<=nums.size();i++) {
            if(nums[i-1]!=i)
                break;    
        }
        return i;
    }
    // 1.暴力法：排序，然后从头遍历看哪个正数没了
    // 2.哈希法：观察样例，若要找出没有出现的最小正整数，则说明只可能出现1～数组大小范围的数字
    // 这样可以利用原数组，把相应的值填入若数组下标和内容不符则说明缺失了。
    // 这个题目有很多边界条件需要注意，如如果某个位子已经有了正确的数字就不需要也不能在交换了否则会死循环
};
// @lc code=end

