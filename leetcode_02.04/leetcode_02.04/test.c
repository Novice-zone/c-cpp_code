//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//
//你不需要 保留 每个分区中各节点的初始相对位置。

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//struct ListNode* partition(struct ListNode* head, int x) {
//    struct ListNode* cur = head;
//    if (cur == NULL)
//        return NULL;
//    struct ListNode* gGuard, *gTail;
//    struct ListNode* lGuard, * lTail;
//    gGuard = (struct ListNode*)malloc(sizeof(struct ListNode));
//    lGuard = (struct ListNode*)malloc(sizeof(struct ListNode));
//    
//    gTail = gGuard;
//    lTail = lGuard;
//    gGuard->next = NULL;
//    lGuard->next = NULL;
//
//    while (cur)
//    {
//        if (cur->val >= x)
//        {
//            gTail->next = cur;
//            gTail = gTail->next;
//        }
//        else
//        {
//            lTail->next = cur;
//            lTail = lTail->next;
//        }
//        cur = cur->next;
//    }
//
//    //链接
//    lTail->next = gGuard->next;
//
//    //将末尾置空防止环生成
//    gTail->next = NULL;
//
//    //返回新头结点
//    head = lGuard->next;
//
//    //释放malloc的空间
//    free(gGuard);
//    free(lGuard);
//
//    return head;
//}


//######################################################################################################################
//LCR 027. 回文链表
//给定一个链表的 头节点 head ，请判断其是否为回文链表。
//
//如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

//找到链表中间的节点（两个中间则返返回第二个节点）
struct ListNode* middleNode(struct ListNode* head)
{
    //如果 head 是 NULL，fast->next 会导致空指针解引用。 添加空指针检查!!!!!!!!!!!!!!!!!
    if (head == NULL)
        return NULL;

    //快慢指针
    struct ListNode* fast, * slow;
    fast = head;
    slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast->next != NULL)
            fast = fast->next;
    }
    return slow;

}

//反转链表，返回新头节点
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    if (cur == NULL)
        return NULL;
    struct ListNode* newHead = NULL;//初始化避免后面可能的操作出现未定义的行为
    while (cur)
    {
        struct ListNode* next = cur->next;//不会产生NULL->next的情况
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;
}


bool isPalindrome(struct ListNode* head) {
    //找中间节点
    struct ListNode* midNode = middleNode(head);
    if (midNode == NULL)
        return true;
    //直接使用了 middleNode 和 reverseList 的结果，需要检查它们是否为 NULL。如果链表为空，可能会导致空指针解引用。

    //从midNode逆置后面的链表
    struct ListNode* newMidNode = reverseList(midNode);
    if (newMidNode == NULL)
        return true;

    //cur遍历链表前一半与newMidNode比较
    struct ListNode* cur = head;
    while (newMidNode)
    {
        if (cur->val != newMidNode->val)
        {
            return false;
        }
        else
        {
            cur = cur->next;
            newMidNode = newMidNode->next;
        }
    }
    return true;
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
    node3->val = 3;
    node4->val = 3;
    node5->val = 2;
    node6->val = 1;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    bool a=isPalindrome(node1);
    printf("函数真假为：%d\n", a);

    return 0;
}