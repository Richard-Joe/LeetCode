#include <stdio.h>

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode head;
    struct ListNode *tail = &head;
    int carry = 0;
    while (l1 && l2) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        tail->next = node;
        tail = node;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        tail->next = node;
        tail = node;
        l1 = l1->next;
    }

    while (l2) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        tail->next = node;
        tail = node;
        l2 = l2->next;
    }

    if (carry) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = carry;
        tail->next = node;
        tail = node;
    }

    return head.next;
}

void main()
{
}
