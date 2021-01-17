
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p1 = head, *p2 = head;

    int i = 1;
    while (i++ <= n) p2 = p2->next;

    if (!p2) return head->next;

    while (p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }

    if (p1->next) p1->next = p1->next->next;
    else p1->next = NULL;

    return head;
}