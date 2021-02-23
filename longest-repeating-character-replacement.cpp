#include"headfile.h"
using namespace std;

class Solution {
public:
	int characterReplacement(string s, int k) {
		//	int result = 1;
		//	for (int i = 0; i < s.size(); ++i) {
		//		int left = i;
		//		int numK = k;
		//		int ans = 1;
		//		while (--left >= 0 && numK >= 0)
		//		{
		//			if (s[left] != s[i]) {
		//				ans = --numK >= 0 ? ans + 1 : ans;;
		//			}
		//			else
		//			{
		//				++ans;
		//			}
		//		}
		//		result = max(result, ans);
		//	}
		//	return result;
		//}
		int n = s.size();
		vector<int> num(26, 0);
		int left = 0, right = 0;
		int maxn = 0;
		while (right < n)
		{
			num[s[right] - 'A']++;
			maxn = max(maxn, num[s[right] - 'A']);
			if (right - left + 1 - maxn > k) {
				num[s[left] - 'A']--;
				left++;
			}
			right++;
		}
		return right - left;
	}
};

int main() {
	Solution s;
	s.characterReplacement("AABABBA", 1);
}