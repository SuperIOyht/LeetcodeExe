#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int len = s.size();
		unordered_map<char, char> hash;
		unordered_map<char, char> hash2;
		for (int i = 0; i < len; i++)
		{
			if ((hash.count(s[i]) && hash2[t[i]] != s[i]) || (hash[s[i]] != t[i] && hash2.count(t[i])))
			{
				return false;
			}
			hash[s[i]] = t[i];
			hash2[t[i]] = s[i];
		}
		return true;
	}
};