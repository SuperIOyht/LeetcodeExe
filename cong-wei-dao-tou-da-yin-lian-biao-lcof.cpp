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
	vector<int> reversePrint(ListNode* head) {
		vector<int> ans;
		ListNode* temp = head;
		while (temp != nullptr)
		{
			ans.push_back(temp->val);
			temp = temp->next;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};