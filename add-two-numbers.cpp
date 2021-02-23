#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int cur = 0;
		ListNode* ans = new ListNode(NULL);
		ListNode* ansNext = ans;
		while(l1 != nullptr || l2 !=nullptr || cur != 0){
			if (l1 != nullptr) {
				cur += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				cur += l2->val;
				l2 = l2->next;
			}
			ansNext->next = new ListNode(cur % 10);
			ansNext = ansNext->next;
			cur = cur / 10;
		}
		return ans->next;
	}
};
int main() {
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	Solution s;
	s.addTwoNumbers(l1, l2);
}