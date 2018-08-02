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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2;
        int c;
        if (n == 0 && head == NULL) return head;
        c = 0;
        p1 = head;
        p2 = head->next;
        while (p2 != NULL) {
            if (c >= n) {
                p1 = p1->next;
            }
            p2 = p2->next;
            c++;
        }
        if (c + 1 < n) {
            return head;
        } else if (c + 1 == n) {
            p2 = head;
            head = p2->next;
        } else {
            p2 = p1->next;
            p1->next = p2->next;
        }

        delete p2;
        return head;
    }
};
