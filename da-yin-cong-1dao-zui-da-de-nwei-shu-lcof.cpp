#include"headfile.h"
using namespace std;

class Solution {
public:
	int n;
	vector<char> loop = vector<char>({ '0','1','2','3','4','5','6','7','8','9' });
	vector<string> ans;
	string num;
	vector<string> printNumbers(int n) {
		this->n = n;
		num.resize(n);
		dfs(0);
		return ans;
	}
	void dfs(int x) {
		if (n == x) {
			ans.push_back(num);
			return;
		}
		for (auto& it:loop) {
			num[x] = it;
			dfs(x + 1);
		}
	}
};

int main() {
	Solution s;
	s.printNumbers(2);
}