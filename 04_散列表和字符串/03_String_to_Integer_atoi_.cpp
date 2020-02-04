// - [String to Integer (atoi)（字符串转换整数 (atoi)）](https://leetcode-cn.com/problems/string-to-integer-atoi/)
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int state=0;// 0 find + - digit  ; 1 find digit ;-1 overflow ;-2 wrong char
        long long ret=0;  
        int sign=1;    
        for(char c:str){
            if(state==0){
                if(c=='+'){
                    state=1;
                }
                else if(c=='-'){
                    state=1;
                    sign=-1;
                }
                else if(isdigit(c)){
                    state=1;
                    ret*=10;
                    ret+=(long long )(c-'0');
                }
                else if(c==' ')continue;
                else state=-2;
            }
            else if(state==1){
                if(isdigit(c)){
                    ret*=10;
                    ret+=(long long )(c-'0');
                    if(ret>INT_MAX)
                    {
                        state=-1;
                    }
                }else{
                    state=-2;
                }
            }
            else if(state==-2){
                return int(ret*sign);
            }
            else if(state==-1){
                if(sign==1)return INT_MAX;
                else if(sign==-1) return INT_MIN;
            }
            
        }
        if(state==-2){
                return int(ret*sign);
            }
            else if(state==-1){
                if(sign==1)return INT_MAX;
                else if(sign==-1) return INT_MIN;
            }
        return int(ret*sign);
    }
};
int main(){

    return 0;
}