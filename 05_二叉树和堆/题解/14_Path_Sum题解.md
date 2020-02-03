# Path Sum（路径总和）题解

- [Path Sum（路径总和）](https://leetcode-cn.com/problems/path-sum/)

这题比较简单，用回溯法，每次遍历到叶子结点时判断加到当前结点时总和等不等于sum。需要注意判断累积和时需要加上本结点的值否则肯定错。

通过使用flg标记，当flg为true时递归终止，每次遍历到叶子结点时若不是答案则会回退到根遍历另一个分支。

需要注意的是，要单独考虑树为空的情况，此时一定返回false；

[LeetCode题解](https://leetcode-cn.com/problems/path-sum/solution/lu-jing-zong-he-by-leetcode/)