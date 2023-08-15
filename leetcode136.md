# Leetcode 136: 只出现一次的数字 - 2023/8/14
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。 

```
示例 1：
输入：nums = [2,2,1]
输出：1
```

```
示例 2：
输入：nums = [4,1,2,1,2]
输出：4
```

# Analysis
xor的特性，比较巧思，可以记一下

# Code blcok
```
int singleNumber(int* nums, int numsSize){
    int n = nums[0];

    /* 题目是需要找到数组中不同的数值， 利用xor的特性，如果不同，则为1，相同为0 */
    for (int i = 1; i < numsSize; i++) {
        n = n ^nums[i];
    }

    return n;
}
```