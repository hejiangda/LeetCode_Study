# Climbing Stairs（爬楼梯）题解

- [Climbing Stairs（爬楼梯）](https://leetcode-cn.com/problems/climbing-stairs/)

[LeetCode题解](https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/)

这题比较简单，爬楼梯可以分解成两种情况：从当前楼梯爬一个台阶和从当前楼梯爬两个台阶。

这样爬n个台阶的不同方法数等价于人爬到n-1号台阶后再爬一格以及人爬到n-2号台阶再爬2格，所以递推式为f(n)=f(n-1)+f(n-2)。

记忆化递归，把每次递归的数据保存下来以减少冗余计算

官方题解中的递归法思路为：递归函数f(i,n)返回从第i阶楼梯爬到第n阶楼梯的方法数，f(i,n)=f(i+1,n)+f(i+2,n); f(n-1,n)=1;