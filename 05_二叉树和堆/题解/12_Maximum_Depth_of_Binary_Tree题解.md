# Maximum Depth of Binary Tree（二叉树的最大深度）题解

- [Maximum Depth of Binary Tree（二叉树的最大深度）](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

这题也很基础，该函数能返回二叉树的最大深度，令left和right为左右子树的深度。返回两者最大的并加上本结点增加的深度1。

需要注意当树本身为空时要返回0，否则会因为非法访问崩溃。

[LeetCode题解](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-leetcode/)