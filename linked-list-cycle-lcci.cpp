#include"headfile.h"
using namespace std;


class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* fastNode = head;
		ListNode* slowNode = head;
		while (fastNode != nullptr)
		{
			slowNode = slowNode->next;
			if (fastNode->next == nullptr) {
				return nullptr;
			}
			fastNode = fastNode->next->next;
			if (fastNode == slowNode) {
				ListNode* ptr = head;
				while (ptr != slowNode)
				{
					ptr = ptr->next;
					slowNode = slowNode->next;
				}
				return ptr;
			}
		}
		return fastNode;
	}
};