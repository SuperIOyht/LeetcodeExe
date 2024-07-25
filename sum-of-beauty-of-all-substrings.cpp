#include"headfile.h"
using namespace std;

class Solution {
public:
	int beautySum(string s) {
		int n = s.size();
		if (n < 3) {
			return 0;
		}
		int ans = 0;
		for (int i = 2; i < n; ++i) {
			int left = 0, right = 0;
			vector<int> cnt(26);
			while (right < n)
			{
				cnt[s[right] - 'a']++;
				if (right - left == i) {
					ans += *max_element(cnt.begin(), cnt.end()) - get_min(cnt);
					cnt[s[left] - 'a']--;
					++left;
				}
				++right;
			}
		}
		return ans;
	}
	int get_min(vector<int>cnt) {
		int min = INT_MAX;
		for (int i = 0; i < cnt.size(); ++i) {
			if (cnt[i]) {
				min = std::min(min, cnt[i]);
			}
		}
		return min;
	}
};

//int main() {
//	Solution s;
//	s.beautySum("aabcb");
//}