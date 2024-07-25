#include"headfile.h"
using namespace std;

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* curr = head;
		while (curr != nullptr)
		{
			ListNode* temp = curr->next;
			curr->next = pre;
			pre = curr;
			curr = temp;
		}
		return pre;
	}
};

int main() {
	Solution s;
	ListNode* a = &ListNode(1);
	ListNode* b = &ListNode(2);
	ListNode* c = &ListNode(3);
	ListNode* d = &ListNode(4);
	ListNode* e = &ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	s.reverseList(a);
}