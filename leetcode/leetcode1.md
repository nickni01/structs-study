# Leetcode 1: 两数之和 - 2023/7/24
给定一个整数数组`nums`和一个整数目标值`target`，请你在该数组中找出和为目标值 `target`的那**两个**整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

```
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```
```
示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

# Analysis
目前采用解法1，采用两个for循环查找遍历数组中的数字，计算两数之和，若相等，则记录后退出

# Code blcok
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0;
    int j = 0;
    int *a = NULL;

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                a = (int *)malloc(sizeof(int) * 2);
                a[0] = i;
                a[1] = j;
                *returnSize = 2;
                return a;
            }
        }
    }
    *returnSize = 0;
    return a;
}
```

TODO: 采用哈希表来查找