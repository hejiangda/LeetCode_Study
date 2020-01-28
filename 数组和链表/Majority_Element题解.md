# Majority Element（求众数）题解

- [Majority Element（求众数）](https://leetcode-cn.com/problems/majority-element/)

这道题很容易想到使用哈希表，但它还有一个非常巧妙的做法，很烧脑。

完整题解可以查看[LeetCode题解](https://leetcode-cn.com/problems/majority-element/solution/qiu-zhong-shu-by-leetcode-2/)

## 方法 6：Boyer-Moore 投票算法

我认为这个方法相当于把数组中的所有数抽象为两种：众数、非众数。

因为我们要求的是哪个是众数，而众数的个数一定大于等于总数的一半，也就是说，若存在众数，如果认为众数与非众数是能够相互抵消，最终留下的一定是众数。

设众数为1，非众数为-1

则可以将整个数组相加，最终相加结果若为正则存在众数，否则不存在。

数组中从candidate被赋值到count减到0的那一段可以被去除，余下部分的多数元素依然是原数组的多数元素。我们可以不断重复这个过程，直到扫描到数组尾部，那么count必然会大于0，而且这个count对应的candinate就是原数组的多数元素。

详细说明可以参考[博客](https://blog.csdn.net/kimixuchen/article/details/52787307)