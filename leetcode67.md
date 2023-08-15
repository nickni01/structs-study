# Leetcode 67: 二进制求和 - 2023/8/5
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

```
示例 1：
输入:a = "11", b = "1"
输出："100"

```
```
示例 2：
输入：a = "1010", b = "1011"
输出："10101"
```

# Analysis
这道题有点小复杂
1. 多申请两个 char长度的memory 因为比较
2. 从a 和 b末尾开始加法 with cy
3. 最后返回时要注意返回的指针起点

# Code blcok
```
char * addBinary(char * a, char * b){
    int lena = strlen(a);
    int lenb = strlen(b);
    int maxlen = lena > lenb ? lena : lenb;
    char *rc = (char *)malloc(sizeof(char) * (maxlen + 1 + 1)); /* including cy and '\0' */

    rc[maxlen + 1] = '\0';
    char *pa = a + lena - 1;
    char *pb = b + lenb - 1;
    int cy = 0;
    int index = maxlen; /* before '\0' */
    int numa = 0;
    int numb = 0;
    int sum = 0;

    while ((pa >= a) || (pb >= b) || cy) {
        numa = 0;
        numb = 0;
        /* if pa is valid */
        if (pa >= a) {
            numa = pa[0] == '0' ? 0 : 1;
        }
        /* if pb is valid */
        if (pb >= b) {
            numb = pb[0] == '0' ? 0 : 1;
        }
    
        sum = numa + numb + cy;
        cy = sum / 2;
        rc[index] = '0' + sum % 2;
        index--;
        pa--;
        pb--;
    }

    return ((rc[0] == '1') ? rc  : (rc + 1));
}
```