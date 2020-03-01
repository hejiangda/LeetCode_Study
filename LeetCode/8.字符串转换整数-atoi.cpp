/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        long long ans=0;
        bool flg=true;
        int sign=1;
        bool flg1=true;
        for (char& x:str) {
            if(isblank(x)){
                if(flg1==true){
                    
                    continue;
                }
                break;
            }
            if(!isdigit(x) and x!='-' and x!='+')break;
            if((x=='-' or x=='+' )) {
               if(flg==false)break;
                flg=false;
                flg1=false;
                if (x=='-') sign=-1;
                continue;
            }
            if (isdigit(x)) {
                flg1=false;
                flg=false;
                ans=ans*10+x-'0';
            }
            if(ans>INT_MAX) {
                if(sign==-1)return INT_MIN;
                else return INT_MAX;
            }
        }
        return sign==1?ans:-ans;
    }
};
// @lc code=end

