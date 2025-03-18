#define _CRT_SECURE_NO_WARNINGS 1
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA, * tailB;
    tailA = headA;
    tailB = headB;
    int lenA = 1, lenB = 1;
    while (tailA)
    {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB)
    {
        tailB = tailB->next;
        lenB++;
    }
    int gap = abs(lenA - lenB);//计算长度差

    struct ListNode* longNode = headA, * shortNode = headB;
    if (lenA < lenB)
    {
        longNode = headB;
        shortNode = headA;
    }
    while (gap--)
    {
        longNode = longNode->next;
    }//长的链表走长度差步，同步“起点”

    while (longNode)
    {
        if (longNode != shortNode)
        {
            longNode = longNode->next;
            shortNode = shortNode->next;
        }
        else
        {
            return longNode;
        }
    }

    return NULL;
}