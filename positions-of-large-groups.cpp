#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		int begin = 0, end = 0;
		vector<vector<int>> ans;
		S += "A";
		for (int i = 0; i < S.size(); i++) {
			if (S[i] != S[begin])
			{
				if (i - begin >= 3) {
					ans.push_back({ begin, i-1 });
				}
				begin = i;
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.largeGroupPositions("abcdddeeeeaabbbcd");
	return 0;
}