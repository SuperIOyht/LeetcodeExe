#include"headfile.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* root = new ListNode(0, head);
        ListNode* mid = root, * end = root;
        while (end != nullptr && end->next != nullptr) {
            mid = mid->next;
            end = end->next->next;
        }
        ListNode* second_head = mid->next;
        mid->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(second_head);
        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* root = new ListNode();
        ListNode* temp = root;
        while (left != nullptr && right != nullptr) {
            if (left->val > right->val) {
                temp->next = right;
                right = right->next;
            }
            else {
                temp->next = left;
                left = left->next;
            }
            temp = temp->next;
        }
        if (left != nullptr) {
            temp->next = left;
        }
        else {
            temp->next = right;
        }
        return root->next;
    }
};

//int main() {
//    ListNode* node4 = new ListNode(4);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node1 = new ListNode(1);
//    ListNode* node3 = new ListNode(3);
//    node4->next = node2;
//    node2->next = node1;
//    node1->next = node3;
//    Solution s;
//    s.sortList(node4);
//}