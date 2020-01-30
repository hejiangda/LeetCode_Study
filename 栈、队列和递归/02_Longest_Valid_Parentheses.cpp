// - [Longest Valid Parentheses（最长有效的括号）](https://leetcode-cn.com/problems/longest-valid-parentheses/)
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int longestValidParentheses(string s) {
            vector<int> num;
            stack<int> st;
            int n=s.size();
            int k=1;
            map<int,int> mp;
            mp[0]=0;
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    st.push(k);
                    num.push_back(k);
                    mp[k]++;
                    k++;
                }else{
                    if(st.empty()){
                        num.push_back(0);    
                    }
                    else{
                        num.push_back(st.top());
                        mp[st.top()]++;
                        st.pop();
                    }
                }
            } 
            for(int i=0;i<n;i++){
                if(mp[num[i]]>=2)
                    num[i]=1;
                else num[i]=0;
            }
            
            int maxsize=0;
            int sum=0;
            
            for(int i=0;i<n;i++){
                if(num[i]==0)sum=0;
                else{
                    sum++;
                }
                if(sum>maxsize)
                    maxsize=sum;
            }
            return maxsize;

        }
};

int main(){
    Solution s;
    cout<<s.longestValidParentheses(")()())")<<endl;
    return 0;
}