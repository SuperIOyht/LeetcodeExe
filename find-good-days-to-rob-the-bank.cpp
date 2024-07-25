#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		int size = security.size();
		vector<int> left(size);
		vector<int> right(size);
		for (int i = 1; i < size; ++i) {
			if (security[i] <= security[i - 1]) {
				left[i] = left[i - 1] + 1;
			}
			if (security[size - i - 1] <= security[size - i]) {
				right[size - i - 1] = right[size - i] + 1;
			}
		}
		vector<int> ans;
		for (int i = time; i < size - time; ++i) {
			if (left[i] >= time && right[i] >= time) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};
