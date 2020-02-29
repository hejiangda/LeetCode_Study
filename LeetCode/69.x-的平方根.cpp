/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x<2)return x;
        long long  left=mySqrt(x>>2)<<1;
        long long  right=left+1;
        return right*right>x?left:right;
    }
    // 1. 二分法，在区间内查找mid**2=x
    // 2.递归，mySqrt(x)=2*mySqrt(x/4)
    // 3.牛顿法，求f(x)的零点，取x0为零点的近似值，过x0,f(x0)作切线
    // y=f'(x0)(x-x0)+f(x0)求出x轴交点x1
    // 以x1为新近似值，x1=x0-f(x0)/f'(x0)依次类推
    // xn+1=xn-f(xn)/f'(xn)
    // 当xn+1与零点的误差小于设定的误差时就得到了答案
};
// @lc code=end

