#include"headfile.h"
using namespace std;

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		unordered_map<char, int> hash;
		for (int i=0;i<order.size();i++)
		{
			hash[order[i]] = i;
		}
		int len = words.size();
		for (int i = 0; i < len - 1; i++)
		{
			int j;
			for (j = 0; j < min(words[i].size(), words[i+1].size()); j++)
			{
				if (hash[words[i][j]] < hash[words[i+1][j]])
				{
					break;
				}
				else if (hash[words[i][j]] > hash[words[i + 1][j]]) {
					return false;
				}
			}
			if (j != words[i].size() && j == words[i + 1].size())
			{
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	vector<string> a({ "kuvp","q" });
	s.isAlienSorted(a, "ngxlkthsjuoqcpavbfdermiywz");

}