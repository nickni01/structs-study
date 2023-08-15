# Leetcode 27: 搜索插入位置 - 2023/8/2
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。


```
示例 1：
输入: nums = [1,3,5,6], target = 5
输出: 2

```
```
示例 2：
输入: nums = [1,3,5,6], target = 2
输出: 1
```

# Analysis
第一次接触二分法，也比比划划了小一会，有点意思
1. 二分法来标记头和尾
2. 用 (right - left) / 2 + left 来定位mid
3. 如果mid > target，右节点左移
4. 如果mid < target, 左节点右移
5. 对于边界条件，可以取极限值来考虑

# Code blcok
```
int searchInsert(int* nums, int numsSize, int target){
    /* 二分法 标记头尾*/
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    while (left <= right) {
        /* 计算中间节点 */
        mid = ((right - left) / 2) + left;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            /* 移动右节点到中间节点前 */
            right = mid - 1;
        } else {
            /* 移动左节点到中间节点后 */
            left = mid + 1;
        }
    }

    return left;
}
```