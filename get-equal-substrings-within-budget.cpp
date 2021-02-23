#include"headfile.h"
using namespace std;

class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int n = s.size();
		vector<int> cost(n);
		int ans = 0, num = 0;
		int cur_cost = 0;
		for (int i = 0; i < n; i++) {
			cost[i] = abs(s[i] - t[i]);
		}
		
		int left = 0, right = 0;
		while (right < n )
		{
			if (cur_cost + cost[right] <= maxCost) {
				++num;
				cur_cost += cost[right];
				++right;
			}
			else
			{
				if (left == right) {
					++left;
					++right;
				}
				else
				{
					cur_cost -= cost[left];
					++left;
					--num;
				}
			}
			ans = max(ans, num);
		}
		return ans;
	}
};
int main() {
	string a = "abcd";
	string b = "cdef";
	Solution s;
	s.equalSubstring(a, b, 1);
}