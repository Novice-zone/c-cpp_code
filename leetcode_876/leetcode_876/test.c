#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。

//如果有两个中间结点，则返回第二个中间结点。

//Definition for singly - linked list.

struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* middleNode(struct ListNode* head) {
    //找尾
    int count = 0;//链表长度
    struct ListNode* endNode = head;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        while (endNode)
        {
            endNode = endNode->next;
            count++;
        }
        count = count / 2;//两个头结点可以返回第二个
        for (int i = 0; i < count; i++)
        {
            head = head->next;
        }
        return head;
    }

}