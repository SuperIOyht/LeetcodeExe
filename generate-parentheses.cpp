#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<string> results;
	vector<string> generateParenthesis(int n) {
		if (n==0)
		{
			return results;
		}
		recursion("", n, n);
		return results;
	}

	//剩余下的right 要大于 left
	void recursion(string ans, int left, int right) {
		if (left == 0 && right == 0)
		{
			results.push_back(ans);
			return;
		}
		if (left == right)
		{
			recursion(ans + '(', left - 1, right);
		}
		else if  (right > left) {
			if (left > 0)
			{
				recursion(ans + '(', left-1, right);
			}
			recursion(ans + ')', left, right-1);
		}
	}
};