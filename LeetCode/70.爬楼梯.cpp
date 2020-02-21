/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if ( stairs.size() < n )
            stairs.resize( n + 1 );
        if( stairs[n] != 0 )
            return stairs[ n ];
        if( n == 1 ) {
            stairs[ 1 ] = 1;
            return 1;
        }
        else if ( n == 2 ){
            stairs[ 2 ] = 2;
            return 2;
        }
        int oneStair = climbStairs( n - 1 );
        int twoStair = climbStairs( n - 2 );
        int sum = oneStair + twoStair;
        stairs[ n ] = sum;
        return sum;
    }
    vector<int> stairs;
};
// @lc code=end

// 1. 把问题分解，爬到当前阶台阶等于爬到前一阶台阶后再爬一阶或爬到前两阶台阶后再爬两阶。
// 2. 