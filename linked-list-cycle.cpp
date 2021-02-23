#include<iostream>
#include<vector>
#include"ListNode.h"

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return false;
		}
		ListNode *pointSlow = head, *pointFast = head->next;
		while (pointSlow != pointFast)
		{
			if (pointFast ==nullptr || pointFast->next == nullptr) {
				return false;
			}
			pointSlow = pointSlow->next;
			pointFast = pointFast->next->next;
		}
		return true;
	}
};