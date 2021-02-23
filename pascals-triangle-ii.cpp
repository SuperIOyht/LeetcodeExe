#include"headfile.h"
using namespace std;


class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> Ans(rowIndex + 1);
		Ans[0] = 1;
		for (int i = 1; i <= rowIndex; i++) {
			for (int j = i; j > 0; j--) {
				Ans[j] += Ans[j - 1];
			}
		}
		return Ans;
	}
};