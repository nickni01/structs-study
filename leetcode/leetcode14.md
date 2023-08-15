# Leetcode 14: 最长公共前缀 - 2023/7/27
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

```
输入：strs = ["flower","flow","flight"]
输出："fl"
```
```
示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
```

# Analysis
1. 找到最小长度的字符串，以它作为基准
2. 对最小字符串的每一个字符，逐个去和其他字符串做比较，一旦该字符和其他字符串不匹配，则退出
3. 重新申请空间，拷贝最长公共前缀

# Code blcok
```
char * longestCommonPrefix(char ** strs, int strsSize){
    int i = 0;
    int j = 0;
    int len = 0;
    char *c_str = NULL;

    /* find least str length */
    len = strlen(strs[0]);
    for (i = 1; i < strsSize; i++)  {
        if (strlen(strs[i]) > len) {
            len = strlen(strs[i]);
        }
    }

    for (j = 0; j < len; j++) {
        /* scan all strs for the single char */
        for (i = 0; i < strsSize - 1; i++) {
            if (strs[i][j] != strs[i + 1][j]) {
                break;
            }
        }

        /* check if current char pass */
        if (i != (strsSize - 1)) {
            break;
        }
    }

    if (j > 0) {
        c_str = malloc((j + 1) * sizeof(char));
        memcpy(c_str, strs[0], j);
        c_str[j] = '\0';
        return c_str;
    } else {
        return "";
    }
}
```