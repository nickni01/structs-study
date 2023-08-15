# Leetcode 9: 回文数 - 2023/7/25
给你一个整数 `x` ，如果 `x` 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，`121` 是回文，而 `123` 不是。

```
示例 1：
输入：x = 121
输出：true
```
```
示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```

# Analysis
首先，通过sprintf将数组转化为数组，然后由前向后 + 由后向前遍历数组，判断是否相等；
不相等时则退出

# Code blcok
```
bool isPalindrome(int x){
    char a[100] = {0};
    int i = 0;
    int j = 0;

    sprintf(a, "%d", x);
    j = strlen(a) - 1;

    for (i = 0; i < j; i++, j--) {
        if (a[i] != a[j]) {
            return false;
        }
    }

    return true;    
}
```