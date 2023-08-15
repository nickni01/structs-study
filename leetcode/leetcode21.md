# Leetcode 21: 合并两个有序链表 - 2023/7/31
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

```
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```
```
示例 2：
输入：l1 = [], l2 = []
输出：[]
```

# Analysis
1. 分析题意，首先需要新建一个链表头，然后返回的链表是把两个链表拼起来的
2. 判断两个链表的结点，将新建的链表头指向小的那个节点，先移动p3->next,再移动p3, 再移动p2或p1

# Code blcok
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p3 = list3;
    struct ListNode* head = p3;

    if (NULL == list1) {
        return list2;
    } else if (NULL == list2) {
        return list1;
    } else {
        /* do nothing */
    }

    while(list1 && list2) {
        if (list1->val < list2->val) {
            p3->next = list1;
            p3 = list1;
            list1 = list1->next;
        } else {
            p3->next = list2;
            p3 = list2;
            list2 = list2->next;
        }
    }

    if (list1) {
        p3->next = list1;
    }
    if (list2) {
        p3->next = list2;
    }

    return head->next;
}
```