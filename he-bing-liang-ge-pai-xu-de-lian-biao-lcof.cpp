#include"headfile.h"
using namespace std;

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode();
		ListNode* temp = head;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val) {
				temp->next = l1;
				temp = temp->next;
				l1 = l1->next;
			}
			else
			{
				temp->next = l2;
				temp = temp->next;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr) {
			temp->next = l1;
		}
		if (l2 != nullptr) {
			temp->next = l2;
		}
		return head->next;
	}
};