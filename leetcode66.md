# Leetcode 66: 加一 - 2023/8/4
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。


```
示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

```
```
示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
```

# Analysis
这道题也蛮有意思的，一开始看反了数组顺序，后来发现有点小难度，因为要考虑进位
1. 多申请一个int的memory
2. add with cy, 注意val[i + 1]
3. 最后判断是否还有cy的存在

# Code blcok
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int cy = 0;
    int i = 0;
    int j = 1;
    int *val = malloc(sizeof(int) * (digitsSize + 1));

    for (i = digitsSize - 1; i >= 0; i--) {
        /* add with cy */
        val[(i + 1)] = digits[i] + cy + j;
        cy = 0;
        j = 0;

        /* if overflow, cy = 1 */
        if (val[(i + 1)]  == 10) {
            cy = 1;
            val[(i + 1)] = 0;
        }
    }

    if (cy) {
        val[i + 1] = 1;
        *returnSize = digitsSize + 1;
        return val;
    }

    *returnSize = digitsSize;
    return (val + 1);
}
```