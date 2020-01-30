# Evaluate Reverse Polish Notatio（逆波兰表达式求值）题解

 - [Evaluate Reverse Polish Notatio（逆波兰表达式求值）](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)

 这题就是后缀表示法计算求值，后缀表示法是 a b op 转换成正常的中缀表示法就是 a op b 后缀表示法可以把表达式中的括号省略方便计算机计算。

 该题只需要判断字符串是否是操作符，若是操作符则取两个操作数计算，否则把字符串转换成数字压栈，计算的结果也要压栈。

 判断是否是数字、操作符可以直接用字符串比较即 x=="+" 这样写比较简洁。