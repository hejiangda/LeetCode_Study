#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left,right;
        left=0;right=numbers.size()-1;
        vector<int> ret;
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum==target){
                ret.push_back(left+1);
                ret.push_back(right+1);
                break;
            }else if(sum>target){
                right--;
            }else if(sum<target){
                left++;
            }
        }
        return ret;
    }
};