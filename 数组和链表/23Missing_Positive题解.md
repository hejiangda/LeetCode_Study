# Missing Positive（求缺失的第一个正数）题解

- [Missing Positive（求缺失的第一个正数）](https://leetcode-cn.com/problems/first-missing-positive/)

这道题虽然标注为难题，但是可以直接排序解决。

如果遵守题目的要求，即限制时间复杂度为O(n)，空间复杂度为O(1，这题的解法确实不容易想到。

我的方法和[LeetCode题解](https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/)的解法是一致的，通过分析可以知道，所求的数字一定在1到数组大小+1这个范围内，可以忽略0、负数以及大于n的数字。接下来把数组的每个位置当成一个桶，如`[0]`用来存放所有值为`1`的数字；`[1]`用于存放所有值为`2`的数字……这样通过交换把所有数字放到它应该在的位置后就相当于完成了一次桶排序，接下来遍历数组查看哪个桶里的数字和应存放的不一致即可得到答案（将变量从1累加到第一个不一致位置即为答案）。

官方的题解是另一种解法有点繁琐[LeetCode题解](https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode/)

