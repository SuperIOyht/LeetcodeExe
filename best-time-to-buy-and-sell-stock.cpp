#include"headfile.h"
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0) {
			return 0;
		}
		vector<int> dp(len, 0);
		int minele = INT_MAX;
		for (int i = 1; i < len; i++)
		{
			minele = min(minele, prices[i - 1]);
			dp[i] = max(dp[i - 1], prices[i] - minele);
		}
		return dp[len - 1];
	}
};
int main() {
	Solution s;
	vector<int> a({ 7,1,5,3,6,4 });
	s.maxProfit(a);
}