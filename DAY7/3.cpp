#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy, *curr = head, *next = nullptr;

        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        }

        curr = prev->next;

        while (len >= k) {
            curr = prev->next;
            next = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            len -= k;
        }

        return dummy.next;
    }
};
