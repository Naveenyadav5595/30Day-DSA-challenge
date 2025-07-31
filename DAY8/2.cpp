#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;

        ListNode dummy(0);
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = &dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            ListNode* nextTemp = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = nextTemp;
        }

        return dummy.next;
    }
};
