#include"headfile.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		unordered_map<int, int> hash;
		ListNode* temp, *pre = new ListNode();
		pre->next = head;
		temp = head;
		while (temp != nullptr)
		{
			if (!hash.count(temp->val)) {
				hash[temp->val] = 1;
				pre = temp;
				temp = temp->next;
			}
			else
			{
				pre->next = temp->next;
				temp = temp->next;
			}
		}
		return head;
	}
};

