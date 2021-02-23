#include"headfile.h"
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> hash1(26, 0);
		vector<int> hash2(26, 0);
		for (int i = 0; i < s1.size(); i++) {
			++hash1[s1[i] - 'a'];
		}
		int k = s1.size();
		int len = s2.size();
		int right = 0, left = 0;
		int cur_len = 0;
		while (right < len)
		{
			if (cur_len < k) {
				++hash2[s2[right] - 'a'];
				++right;
				++cur_len;
			}
			else if (cur_len == k) {
				if (hash1 == hash2) {
					return true;
				}
				else
				{
					--hash2[s2[left] - 'a'];
					++left;
					++hash2[s2[right] - 'a'];
					++right;
				}
			}
		}
		if (hash1 == hash2) {
			return true;
		}
		return false;
	}
};
int main() {
	Solution s;
	s.checkInclusion("ab", "eidbaooo");
}