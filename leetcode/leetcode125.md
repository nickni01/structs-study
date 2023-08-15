# Leetcode 125. 验证回文串 - 2023/8/11
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

 

```
示例 1：
输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
```

```
示例 2：
输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
```

# Analysis
这个题是标准的找回文数，但是多加了一点点要求
1. 需要先将数组中 字母改为小写，且去除所有非数字与字母的字符
2. 再通过双指针判断，逻辑不难

# Code blcok
```
bool isPalindrome(char * s){
    int len = strlen(s);
    char *head = NULL;
    char *tail = NULL;
    int i = 0;
    int j = 0;

    for (i = 0; i< len; i++) {
        if (s[i]>='a' && s[i]<='z') {
            s[j]=s[i];
            j++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[j] = s[i] + 'a'-'A';
            j++;
        } else if (s[i] >='0' && s[i] <= '9') {
            s[j]=s[i];
            j++;
        }
    }
    s[j]='\0';
    head = s;
    tail = s + j - 1;

    while (head < tail) {
        if (*head != *tail) {
            break;
        }
        head++;
        tail--;
    }

    if (head >= tail) {
        return true;
    } else {
        return false;
    }
}
```