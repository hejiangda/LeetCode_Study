/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        int mp1[30]{0};
        int mp2[30]{0};
        for(char x:s) {
            mp1[x-'a']++;
        }
        for(char x:t) {
            mp2[x-'a']++;
        }
        for(int i=0;i<26;i++) {
            if(mp1[i]!=mp2[i])return false;
        }
        return true;
    }
};
// @lc code=end

