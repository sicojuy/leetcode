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
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre, *cur, *tmp;
        if (head == NULL || head->next == NULL) return head;
        tmp = head->next;
        head->next = tmp->next;
        tmp->next = head;
        swap(head, tmp);
        pre = tmp;
        cur = pre->next;
        while (cur != NULL && cur->next != NULL) {
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            swap(cur, tmp);
            pre->next = cur;
            pre = tmp;
            cur = pre->next;
        }
        pre->next = cur;
        return head;
    }
};