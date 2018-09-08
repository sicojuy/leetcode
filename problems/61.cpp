#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len;
        ListNode *p1, *p2;
        int i;
        if (head == NULL || head->next == NULL || k == 0) return head;
        for (len = 1, p2 = head; p2->next != NULL; p2 = p2->next) len++;
        if (k % len == 0) return head;
        for (k = len - k % len - 1, p1 = head; k > 0; k--) p1 = p1->next;
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        return head;
    }
};