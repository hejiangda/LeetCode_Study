# Sqrt(x) （x 的平方根）题解

 - [Sqrt(x) （x 的平方根）](https://leetcode-cn.com/problems/sqrtx/)

[liweiwei1419题解](https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/)

这题可以用模糊二分法求解，只不过把判断条件变成了`mid*mid<=x`。

另外还可以用牛顿迭代法求解，即使用一阶泰勒展开来代替原函数（若求a的平方根，可以把函数写成f(x)=x*x-a）令函数为零得到x的迭代表达式，当误差小于给定值时即可得到近似解。