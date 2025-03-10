#define _CRT_SECURE_NO_WARNINGS 1
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

#include<stdio.h>
#include<stdlib.h>
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newnode == NULL)
    {
        perror("malloc");
        return NULL;
    }
    while (head->val == val)
    {
        if (head->next != NULL)
        {
            head = head->next;
        }
        else
        {
            head = NULL;
            return head;
        }

    }
    newnode = head;
    while (newnode->next)
    {
        if ((newnode->next)->val != val)
        {
            newnode = newnode->next;
        }
        else
        {
            newnode->next = (newnode->next)->next;
        }
    }
    
    return head;
}