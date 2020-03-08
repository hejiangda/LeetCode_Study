/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double ret=1;
        long long nn=n;
        if(nn<0){
            nn=-nn;
            x=1/x; 
        }
        if(nn==1) {
            return x;
        }else if(nn==0) {
            return 1;
        }
        ret=myPow(x,nn/2);
        if(nn&1) {
            ret=ret*ret*x;    
        }else {
            ret=ret*ret;
        }
        return ret;
    }
};
// @lc code=end

