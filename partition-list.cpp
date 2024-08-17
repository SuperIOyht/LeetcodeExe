
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

int main() {
    Solution s;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    s.partition(node1, 3);
}