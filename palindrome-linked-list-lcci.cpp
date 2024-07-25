/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		stack<int> myStack;
		vector<int> myarray;
		while (head != nullptr)
		{
			myarray.push_back(head->val);
			myStack.push(head->val);
			head = head->next;
		}
		for(int i=0;i<myarray.size();++i)
		{
			if (myStack.top() != myarray[i]) {
				return false;
			}
			myStack.pop();
		}
		return true;
	}
};