# Design Circular Deque（设计一个双端队列）题解

 - [Design Circular Deque（设计一个双端队列）](https://leetcode-cn.com/problems/design-circular-deque/)

 这题考察细节以及对双端循环队列的理解，一开始我把它写成了共享栈，后来发现错了。
 
 双端循环队列需要实现左右都可以插入删除，思考后，令front=-1、last=0，插入时front=(sz+front+1)%sz、last=(sz+last-1)%sz，删除时front=(sz+front-1)%sz、last=(sz+last+1)%sz，这里需要注意加一减一，我在调试的时候就把尾端删除的+1写成了-1导致了错误。另外取队列两端的数据时若队列为空需要返回-1。