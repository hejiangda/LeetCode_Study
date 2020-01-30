// - [Valid Parentheses（有效的括号）](https://leetcode-cn.com/problems/valid-parentheses/)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        for(char c:s){
            if(st.empty()){
                if(mp.find(c)==mp.end())
                    st.push(c);
                else return false;
            }else{
                if(mp.find(c)==mp.end())
                    st.push(c);
                else{
                    if(mp[c]==st.top()){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }

};

int main(){

  return 0;
}