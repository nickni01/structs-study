# Leetcode 20: 有效的括号 - 2023/7/28
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

```
输入：s = "()"
输出：true
```
```
示例 2：
输入：s = "()[]{}"
输出：true
```

# Analysis
1. 分析题意，想到可以把所有的左括号放到栈中，因为每一个左括号，都要遇到第一个右括号，建立一个pairs函数
2. 如果是左括号，入栈；
3. 如果是右括号，查看栈顶是不是对应的左括号，否则错误

# Code blcok
```
char pairs(char a)
{
    if (a == '}') {
        return '{';
    }
    if (a == ']') {
        return '[';
    }
    if (a == ')') {
        return '(';
    }
    return 0;
}

bool isValid(char * s){
    int len = strlen(s);
    char ch = 0;
    if (len % 2 != 0) {
        return false;
    }

    int stack[len + 1];
    int top = 0;

    for (int i = 0; i < len; i++) {
        ch = pairs(s[i]);
        if (ch) {
            /* check stack top */
            if (top == 0 || stack[top - 1] != ch) {
                return false;
            }
            /* pop to stack */
            top--;
        } else {
            /* push to stack */
            stack[top] = s[i];
            top++;
        }
    }

    return top == 0;
}
```