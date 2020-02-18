#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=0,q=1;
        int n=nums.size();
        if(n<=0)return 0;
        while(p!=q and p<n-1 and q<n){
            if(nums[p]==nums[q]){
                q++;
            }else{
                nums[++p]=nums[q++];
            }
        }
        return p+1;
    }
};
int main(){

    return 0;
}