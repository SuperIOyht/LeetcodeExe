#include"headfile.h"
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int len = cost.size();
		if (len == 0)
		{
			return NULL;
		}
		if (len == 1) {
			return cost[0];
		}
		vector<int> dp(len + 1, 0);
		for (int i = 2; i <= len; i++)
		{
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[len];
	}
};

int main() {
	Solution s;
	vector<int> a = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	s.minCostClimbingStairs(a);
}