#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxn=INT_MIN;
        for(int x:nums){
            sum+=x;
            if(sum>maxn)maxn=sum;
            if(sum<0)sum=0;
        }
        return maxn;
    }
};