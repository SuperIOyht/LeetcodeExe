#include"headfile.h"
using namespace std;
class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		vector<int> cus;
		int ans = 0;
		int cur_ans = 0;
		for (int i = 0; i < customers.size(); ++i) {
			if (grumpy[i]) {
				cus.push_back(i);
			}
			else
			{
				ans += customers[i];
			}
		}
		cur_ans = ans;
		int left = 0, right = 0;
		while (right < cus.size())
		{
			if (cus[right] - cus[left] + 1 <= X) {
				cur_ans += customers[cus[right]];
				ans = max(ans, cur_ans);
				++right;
			}
			else
			{
				cur_ans -= customers[cus[left]];
				++left;
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> a({ 1,0,1,2,1,1,7,5 });
	vector<int> b({ 0,1,0,1,0,1,0,1 });
	s.maxSatisfied(a, b, 3);
}