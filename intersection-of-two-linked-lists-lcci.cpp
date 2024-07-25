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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int length_a = 0, length_b = 0;
		ListNode* temp = headA;
		while (temp!= nullptr)
		{
			temp = temp->next;
			length_a++;
		}
		temp = headB;
		while (temp!= nullptr)
		{
			temp = temp->next;
			length_b++;
		}
		if (length_a > length_b) {
			for (int i = 0; i < length_a - length_b; ++i) {
				headA = headA->next;
			}
		}
		else
		{
			for (int i = 0; i < length_b - length_a; ++i) {
				headB = headB->next;
			}
		}
		while (headA != nullptr)
		{
			if (headA == headB) {
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
};