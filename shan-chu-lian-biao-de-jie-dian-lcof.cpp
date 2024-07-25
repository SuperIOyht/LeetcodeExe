#include"headfile.h"
using namespace std;

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head->val == val) {
			return head->next;
		}
		ListNode* temp = head->next;
		ListNode* prev = head;
		while (temp != nullptr)
		{
			if (temp->val == val) {
				prev->next = temp->next;
				return head;
			}
			prev = temp;
			temp = temp->next;
		}
	}
};