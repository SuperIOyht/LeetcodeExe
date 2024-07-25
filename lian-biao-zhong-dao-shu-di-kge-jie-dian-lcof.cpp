#include"headfile.h"
using namespace std;

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* quick = head, *slow = head;
		for (int i = 1; i < k; i++)
		{
			quick = quick->next;
		}
		while (quick != nullptr)
		{
			quick = quick->next;
			slow = slow->next;
		}
		return slow;
	}
};