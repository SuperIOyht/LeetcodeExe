#include"ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* root = new ListNode(0, head);
        ListNode* curr = root;
        int size = 0;
        while (curr->next != nullptr)
        {
            curr = curr->next;
            size++;
        }
        curr->next = root->next;
        ListNode* pre = curr;
        curr = curr->next;
        
        for (int rotation_num = size - (k % size); rotation_num > 0; rotation_num--) {
            pre = curr;
            curr = curr->next;
        }
        pre->next = nullptr;
        return curr;
    }
};