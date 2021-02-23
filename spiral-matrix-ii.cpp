#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n);
		for (int i = 0; i < n;i++) {
			ans[i].resize(n);
		}
		int loop = 0;
		int c = 1;
		while (loop < (n+1)/2)
		{
			for (int i = loop; i < n - loop; i++) {
				ans[loop][i] = c;
				c++;
			}
			for (int i = loop+1; i < n - loop;i++) {
				ans[i][n - loop - 1] = c;
				c++;
			}
			for (int i = n-loop-2; i >= loop; i--) {
				ans[n - loop - 1][i] = c;
				c++;
			}
			for (int i = n-loop-2; i > loop; i--) {
				ans[i][loop]=c;
				c++;
			}
			loop++;
		}
		return ans;
	}
};
int main() {
	Solution s;
	s.generateMatrix(3);
}