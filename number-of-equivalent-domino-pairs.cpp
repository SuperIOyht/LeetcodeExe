#include"headfile.h"
using namespace std;
class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		vector<int> num(100);
		int result = 0;
		for (auto& it : dominoes) {
			int val = it[0] > it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
			result += num[val];
			++num[val];
		}
		return result;
	}
};