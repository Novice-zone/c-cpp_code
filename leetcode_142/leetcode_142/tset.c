﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//
//1.
//不允许修改 链表。
//思路是找到相遇点meet,head和meet每次往前走一步，相遇点就是入口点

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    //先找到相遇点
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    else
    {
        struct ListNode* fast, * slow;
        fast = head; slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                struct ListNode* meet = fast;
                struct ListNode* start = head;
                while (meet != start)
                {
                    meet = meet->next;
                    start = start->next;
                }
                return meet;
            }

        }
        return NULL;//不相遇说明没环
    }
}