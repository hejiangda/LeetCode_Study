// - [Reverse String （反转字符串）](https://leetcode-cn.com/problems/reverse-string/)
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        int len2=len/2;
        for(int i=0;i<len2;i++){
            swap(s[len-i],s[i]);
        }
        return;
    }
};
int main(){

    return 0;
}