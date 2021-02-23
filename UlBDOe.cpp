#include"headfile.h"
using namespace std;
class Solution {
public:
	int minimumOperations(string leaves) {
		int size = leaves.size();
		vector<vector<int>> leaf(size, vector<int>(3));
		leaf[0][0] = (leaves[0] == 'y');
		leaf[0][1] = leaf[0][2] = leaf[1][2] = INT_MAX;
		for (int i = 1; i < size; ++i) {
			int isRed = (leaves[i] == 'r');
			int isYellow = (leaves[i] == 'y');
			leaf[i][0] = leaf[i - 1][0] + isYellow;
			leaf[i][1] = min(leaf[i - 1][0], leaf[i - 1][1]) + isRed;
			if (i >= 2) {
				leaf[i][2] = min(leaf[i - 1][1], leaf[i - 1][2]) + isYellow;
			}
		}
		return leaf[size - 1][2];
	}
};

int main() {
	Solution s;
	s.minimumOperations("rrryyyrryyyrr");
}