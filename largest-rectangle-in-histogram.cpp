#include"headfile.h"
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n==1)
		{
			return heights[0];
		}
		int res = 0;
		stack<int> stack;
		for (int i = 0; i < n; i++)
		{
			while (!stack.empty() && heights[stack.top()] >= heights[i])
			{
				int len = heights[stack.top()];
				stack.pop();
				int weight = i;
				if (!stack.empty())
				{
					weight = i - stack.top() - 1;
				}
				res = max(res, weight * len);
			}
			stack.push(i);

		}
		while (!stack.empty())
		{
			int len = heights[stack.top()];
			stack.pop();
			int weight = n;
			if (!stack.empty())
			{
				weight = n - stack.top() - 1;
			}
			res = max(res, len * weight);
		}
		return res;
	}
};