# Leetcode 27: 找出字符串中第一个匹配项的下标 - 2023/8/1
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。


```
示例 1：
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。

```
```
示例 2：
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
```

# Analysis
这道题一下子就想到了暴力解决，把haystack和needle都循环遍历一遍，双for大法-。-
还有KMP解法，以后再看吧

# Code blcok
```
int strStr(char * haystack, char * needle){

    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    int i = 0;
    int j = 0;

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        if (j == len2) {
            return i;
        }
    }

    return -1;
}
```