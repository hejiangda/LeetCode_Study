// - [Evaluate Reverse Polish Notatio（逆波兰表达式求值）](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string x:tokens){
            if(x=="+"){
                int b=stk.top();stk.pop();
                int a=stk.top();stk.pop();
                stk.push(a+b);
            }
            else if(x=="-"){
                int b=stk.top();stk.pop();
                int a=stk.top();stk.pop();
                stk.push(a-b);
            }
            else if(x=="*"){
                int b=stk.top();stk.pop();
                int a=stk.top();stk.pop();
                stk.push(a*b);
            }
            else if(x=="/"){
                int b=stk.top();stk.pop();
                int a=stk.top();stk.pop();
                stk.push(a/b);
            }
            else {
                int a=stoi(x);
                stk.push(a);
            }
        }
        return stk.top();
    }
};
int main(){
    Solution s;
    vector<string>x={"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout<<s.evalRPN(x)<<endl;
    return 0;
}