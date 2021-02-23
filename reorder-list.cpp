#include"headfile.h"
using namespace std;

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		return prev;
	}

	void reorderList(ListNode* head) {
		ListNode* fast = head, *slow = head;
		while (fast->next->next != nullptr && slow->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* rBegin = slow->next;
		rBegin = reverseList(rBegin);
		slow->next = nullptr;
		ListNode *lBegin = head;
		while (lBegin!=nullptr)
		{
			ListNode* nextL = lBegin->next;
			ListNode* nextR = rBegin->next;
			lBegin->next = rBegin;
			rBegin->next = nextL;
			lBegin = nextL;
			rBegin = nextR;
		}
	}
};

int main() {
	ListNode* a = &ListNode(1);
	a->next = &ListNode(2);
	a->next->next = &ListNode(3);
	a->next->next->next =&ListNode(4);
	Solution s;
	s.reorderList(a);
}