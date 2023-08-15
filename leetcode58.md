# Leetcode 58: 最后一个单词的长度 - 2023/8/3
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。


```
示例 1：
输入：s = "Hello World"
输出：5
解释：最后一个单词是“World”，长度为5。

```
```
示例 2：
输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为4。
```

# Analysis
这道题解的蛮快的，可以想到单词是在两个空格之间的
1. 从后往前，找到第一个非空格
2. 再从后往前，找到第一个空格
3. 这两个中间，就是单词了

# Code blcok
```
int lengthOfLastWord(char * s){
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int last_len = 0;
    char *p = s + len - 1;

    /* 从后往前找，找到第一个非空格 */
    while (*p == ' ') {
        p--;
        i++;
        len--;
    }

    /* 从后往前找，找到第一个空格 */
    j = i;
    while (len > 0 && *p != ' ') {
        p--;
        j++;
        len--;
    }

    return (j - i);
}
```