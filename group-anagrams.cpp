#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> hash;
		vector<vector<string>> res;
		for (auto it:strs)
		{
			string temp = it;
			sort(temp.begin(), temp.end());
			hash[temp].push_back(it);
		}
		for (auto it : hash)
		{
			res.push_back(it.second);
		}
		return res;
	}
};