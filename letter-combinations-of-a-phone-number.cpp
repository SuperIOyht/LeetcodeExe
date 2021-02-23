#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> map = {
	"",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz",
	};
	vector<string> ans;
	string temp;
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) {
			return ans;
		}
		dfs(digits);
		return ans;
	}
	void dfs(string digits) {
		if (!digits.size()) {
			ans.push_back(temp);
			return;
		}
		int num = digits[0] - 48;
		digits = digits.substr(1, digits.size() - 1);
		for (int i = 0; i < map[num].size(); i++) {
			temp.push_back(map[num].at(i));
			dfs(digits);
			temp.pop_back();
		}
	}
};

int main() {
	Solution s;
	s.letterCombinations("");
	return 0;
}