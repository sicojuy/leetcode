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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ghead, *gtail, *cur, *tmp;
        int i;
        if (head == NULL || k == 1) return head;
        cur = head;
        head = new ListNode(0);
        gtail = head;
        while (cur != NULL) {
            ghead = gtail;
            gtail = cur;
            ghead->next = NULL;
            for (i = 0; i < k && cur != NULL; i++) {
                tmp = cur;
                cur = cur->next;
                tmp->next = ghead->next;
                ghead->next = tmp;
            }
            if (i < k) {
                cur = ghead->next;
                ghead->next = NULL;
                while (cur != NULL) {
                    tmp = cur;
                    cur = cur->next;
                    tmp->next = ghead->next;
                    ghead->next = tmp;
                }
            }
        }
        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};