#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* fast = NULL, * slow = NULL;

    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    else
    {
        fast = head->next;
        slow = head;
        while (fast)
        {
            if (fast->val != slow->val)
            {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = NULL;
    }
    return head;
}