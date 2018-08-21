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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3, *p, *n;
        int a;

        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }

        n = new ListNode(0);
        if (l1 == NULL) {
            n->val = l2->val;
            l2 = l2->next;
        } else if (l2 == NULL) {
            n->val = l1->val;
            l1 = l1->next;
        } else {
            n->val = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        a = n->val / 10;
        n->val = n->val % 10;
        l3 = p = n;

        while (1) {
            if (l1 == NULL && l2 == NULL) {
                break;
            }

            n = new ListNode(0);
            if (l1 == NULL) {
                n->val = l2->val + a;
                l2 = l2->next;
            } else if (l2 == NULL) {
                n->val = l1->val + a;
                l1 = l1->next;
            } else {
                n->val = l1->val + l2->val + a;
                l1 = l1->next;
                l2 = l2->next;
            }
            a = n->val / 10;
            n->val = n->val % 10;
            p->next = n;
            p = n;
        }

        if (a > 0) {
            n = new ListNode(0);
            n->val = a;
            p->next = n;
            p = n;
        }
        p->next = NULL;

        return l3;
    }
};