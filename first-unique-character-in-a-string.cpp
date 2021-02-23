#include"headfile.h"
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> hash;
		for (auto it:s)
		{
			++hash[it];
		}
		for (int i=0;i<s.size();++i)
		{
			if (hash[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};