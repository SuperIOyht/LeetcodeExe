#include"headfile.h"
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s) {
		vector<string> words;
		stringstream ssteam(s);
		string buf;
		unordered_map<char, string> hash;
		unordered_map<string, char> hash2;
		while (ssteam>>buf)
		{
			words.push_back(buf);
		}
		if (pattern.size() != words.size())
		{
			return false;
		}
		for (int i = 0; i < pattern.size(); i++)
		{
			if (hash.count(pattern[i]) && hash2[words[i]] != pattern[i])
			{
				return false;
			}
			if(hash2.count(words[i]) && hash[pattern[i]] != words[i])
			{
				return false;
			}
			hash[pattern[i]] = words[i];
			hash2[words[i]] = pattern[i];
		}
		return true;
	}
};