
#include"ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* large_side_root = new ListNode(0, nullptr);
        ListNode* root = new ListNode(0, head);
        ListNode* curr = head, * pre = root, * large_size_curr = large_side_root;
        while (curr != nullptr) {
            if (curr->val >= x) {
                large_size_curr->next = curr;
                large_size_curr = large_size_curr->next;
                curr = curr->next;
                large_size_curr->next = nullptr;
                pre->next = curr;
            }
            else {
                pre = curr;
                curr = curr->next;
            }
        }
        pre->next = large_side_root->next;
        return root->next;
    }
};
