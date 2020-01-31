# Sliding Window Maximum（滑动窗口最大值）题解
- [Sliding Window Maximum（滑动窗口最大值）](https://leetcode-cn.com/problems/sliding-window-maximum/)

[labuladong题解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-dui-lie-by-labuladong/)

labuladong这老哥写的算法解释都很到位接下来可以多看看他公众号的内容。

[LeetCode题解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/)

官方的题解说的不明不白的。

这道题目最重要的一点是当删除旧元素后怎样不需重新遍历就能得到最大值。

在一堆数字中，已知最值，如果给这堆数添加一个数，那么比较一下就可以很快算出最值；但如果减少一个数，就不一定能很快得到最值了，而要遍历所有数重新找最值。

回到这道题的场景，每个窗口前进的时候，要添加一个数同时减少一个数，所以想在 O(1) 的时间得出新的最值，就需要「单调队列」这种特殊的数据结构来辅助了。

作者：labuladong
链接：https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-dui-lie-by-labuladong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

用双端队列可以实现一个单调队列，每次遍历新元素时将其逐个与之前元素对比即取出back端比较后若比前面的小则把它出队，最后把该元素插入，这样可以保证队首元素是最大的。

但只是这样不能解决滑窗的问题，元素已经被删除了，只从队列中的元素个数不能确定是否要删除队首元素，这时只要把队列中记录的数据转换成数组的下标即可，使用数组下标就能在每次遍历时判断该号元素是否需要删除进而实现滑窗。