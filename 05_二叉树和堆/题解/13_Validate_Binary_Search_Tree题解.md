# Validate Binary Search Tree（验证二叉查找树）题解
- [Validate Binary Search Tree（验证二叉查找树）](https://leetcode-cn.com/problems/validate-binary-search-tree/)

这题稍难，思路容易进入误区，即使每个子树都是BST且左右结点满足大小关系也不一定就是BST，BST一定是中序遍历时单调的，如果右子树中出现小于根或左子树的结点那么就不是BST了。

这题比较容易想到的是用一个中序遍历，把前一个结点保存起来，然后每次遍历到结点是判断与前一个结点漫步满足大小关系。

[LeetCode题解](https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode/)

官方题解中的递归法在每次遍历时判断树的值有无超出上下界（即保存之前结点的最值，以解决局部满足定义而全局不满足的问题）