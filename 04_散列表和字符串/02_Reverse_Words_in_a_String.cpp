// - [Reverse Words in a String（翻转字符串里的单词）](https://leetcode-cn.com/problems/reverse-words-in-a-string/)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int n=s.length();
        int right=n-1;
        int left=n-1;
        bool flg=false;
        while(left>=0 and right>=0){
            while(right>=0 and s[right]==' ')right--;
            while(left>0 and s[left-1]!=' ')left--;
            
            for(int h=left;h<=right;h++){
                if(flg and h==left){
                    ret.push_back(' ');
                }
                
                ret.push_back(s[h]);
                flg=true;
            }
            left--;
            right=left;
        }
        while(ret.back()==' ')ret.pop_back();
        return ret;
    }
};
int main(){

    return 0;
}