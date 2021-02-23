#include"headfile.h"
class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		double a[102][102];
		memset(a, 0, sizeof(a));
		a[0][0] = poured;
		for (int i = 0; i <= query_row; i++) {
			for (int j = 0; j <= i; j++) {
				double q = (a[i][j] - 1) / 2;
				if (q > 0) {
					a[i + 1][j] += q;
					a[i + 1][j + 1] += q;
				}
			}
		}
		return min(1.0, a[query_row][query_glass]);
	}
};

int main() {
	Solution s;
	s.champagneTower(2, 1, 1);
	return 0;
}