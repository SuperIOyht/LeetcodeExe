#include"headfile.h"
using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		char ans;
		if (s.size() == 0) {
			return ' ';
		}
		unordered_map<char, int> hash;
		for (int i = 0; i < s.size(); ++i) {
			if (hash.count(s[i])) {
				hash[s[i]] = 0;
			}
			else
			{
				hash[s[i]] ++;
			}
		}
		for (int i = 0; i < s.size(); ++i) {
			if (hash[s[i]] == 1) {
				return s[i];
			}
		}
		return ' ';
	}
};