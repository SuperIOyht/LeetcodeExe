#include"headfile.h"
using namespace std;

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int n = cardPoints.size();
		int right = n - k;
		cardPoints.insert(cardPoints.end(), cardPoints.begin(), cardPoints.end());
		int cur_num = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
		int ans = cur_num;
		for (; right < n; right++) {
			cur_num = cur_num + cardPoints[right + k] - cardPoints[right];
			ans = max(cur_num, ans);
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> a({ 1,2,3,4,5,6,1 });
	s.maxScore(a, 3);
}