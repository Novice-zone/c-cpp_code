#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* tail = NULL;//尾插法
//    struct ListNode* newHead = NULL;
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//            if (newHead == NULL)
//            {
//                newHead = tail = list1;
//                list1 = list1->next;
//            }
//            else
//            {
//                tail->next = list1;
//                list1 = list1->next;
//                tail = tail->next;
//            }
//        }
//        else
//        {
//            if (newHead == NULL)
//            {
//                newHead = tail = list2;
//                list2 = list2->next;
//            }
//            else
//            {
//                tail->next = list2;
//                list2 = list2->next;
//                tail = tail->next;
//            }
//
//        }
//    }
//
//    if (list1==NULL)
//    {
//        tail->next = list2;
//
//    }
//    else
//    {
//        tail->next = list1;
//
//    }
//
//    return newHead;
//}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* guard = NULL, * tail = NULL;
    guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    //哨兵位guard不用检查tail是否为空
    tail->next = NULL;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
    }

    if (list1 == NULL)
    {
        tail->next = list2;
        tail = tail->next;
    }
    else
    {
        tail->next = list1;
        tail = tail->next;
    }

    struct ListNode* head = guard->next;
    return head;
}

int main()
{
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));

    node1->val = 1;
    node2->val = 2;
    node3->val = 4;

    node4->val = 1;
    node5->val = 3;
    node6->val = 4;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    struct ListNode* newnode=mergeTwoLists(node1, node4);
    while (newnode)
    {
        printf("%d->", newnode->val);
        newnode = newnode->next;
    }
    printf("NULL\n");
    return 0;
}