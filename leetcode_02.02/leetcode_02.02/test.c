#define _CRT_SECURE_NO_WARNINGS 1

//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

//注意：本题相对原题稍作改动
//示例：
//输入： 1->2->3->4->5 和 k = 2
//输出： 4

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
int kthToLast(struct ListNode* head, int k)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        for (int i = 1; i < k; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow->val;
}
int main()
{
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    int a=kthToLast(node1, 2);
    printf("%d\n", a);

    return 0;
}









//此处增加203的新解法
// 
// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 
// 
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* newHead = NULL, * tail = NULL;
//    struct ListNode* cur = head;
//
//    while (cur)
//    {
//        if (cur->val != val)
//        {
//            //尾插到新链表newHead，返回newHead
//            if (newHead == NULL)
//            {
//                newHead = cur;
//                tail = cur;
//            }
//            else
//            {
//                tail->next = cur;
//                tail = tail->next;
//            }
//            cur = cur->next;
//
//        }
//        else
//        {
//            struct ListNode* next = cur->next;
//            free(cur);
//            cur = next;
//        }
//    }
//    if (tail == NULL)
//    {
//        return NULL;
//    }
//    tail->next = NULL;
//
//    return newHead;
//}
