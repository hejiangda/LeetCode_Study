# String to Integer (atoi)（字符串转换整数 (atoi)）题解

- [String to Integer (atoi)（字符串转换整数 (atoi)）](https://leetcode-cn.com/problems/string-to-integer-atoi/)

这题考验细心，我没把情况考虑全。用一个状态变量保存当前所处的状态，要注意当循环结束后也要判断状态是否是-1、-2,，否则若恰好加上最后一个数溢出则无法检测到错误，而直接输出。

[LeetCode题解](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/python-1xing-zheng-ze-biao-da-shi-by-knifezhu/)

用正则表达式解这个题是真的简洁。