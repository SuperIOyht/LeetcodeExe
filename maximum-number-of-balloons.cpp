#include"headfile.h"
using namespace std;

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		unordered_map<char,int> hash;
		for (int i = 0; i < text.size(); ++i) {
			hash[text[i]]++;
		}
		int ans = INT_MAX;
		ans = min(ans, hash['a']);
		ans = min(ans, hash['b']);
		ans = min(ans, hash['n']);
		ans = min(ans, hash['o']/2);
		ans = min(ans, hash['l'] / 2);
		return ans;
	}
};