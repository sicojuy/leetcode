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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l, *p, *p1, *p2;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        p1 = l1;        
        p2 = l2;
        if (p1->val > p2->val) {
            l = p2;
            p2 = p2->next;
        } else {
            l = p1;
            p1 = p1->next;
        }
        p = l; 
        while (p1 != NULL && p2 != NULL) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }
        p->next = p1 == NULL ? p2 : p1;
        return l;
    }
};