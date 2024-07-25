#include"headfile.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (auto& it : A) {
			for (auto& it2 : it) {
				if (it2) {
					it2 = 0;
				}
				else
				{
					it2 = 1;
				}
			}
		}
		for (auto& it : A) {
			reverse(it.begin(), it.end());
		}

	}
};