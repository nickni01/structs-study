# Leetcode 83: 删除排序链表中的重复元素 - 2023/8/8
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。

```
示例 1：
输入：head = [1,1,2]
输出：[1,2]

```
```
示例 2：
输入：head = [1,1,2,3,3]
输出：[1,2,3]
```

# Analysis
这道题比较简单，关键是需要意识到一个隐含的条件：由于链表已经是有序的，所以重复的元素都是相邻的。  
然后就是修改指针指向即可。

# Code blcok
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return head;
    }

    struct ListNode* cur = head;
    struct ListNode* tmp_p = NULL;
    /* 往下找节点 */
    while(cur->next) {
        /* 由于链表已经是有序的，所以重复的元素都是相邻的 */
        if (cur->val == cur->next->val) {
            tmp_p = cur->next;
            cur->next = cur->next->next;
            free(tmp_p);
        } else {
            cur = cur->next;
        }
    }

    return head;
}
```