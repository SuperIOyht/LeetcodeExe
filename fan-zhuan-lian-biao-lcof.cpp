#include"headfile.h"
using namespace std;

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		/*
		ListNode* ans_head = new ListNode();
		while (head != nullptr)
		{
			ListNode* temp = head;
			head = head->next;
			temp->next = ans_head->next;
			ans_head->next = temp;
		}
		return ans_head->next;
		*/

		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};