#include"headfile.h"
using namespace std;

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		int n = A.size();
		vector<int> ans;
		for (int i = n - 1; i >= 0; i--)
		{
			K += A[i];
			ans.push_back(K % 10);
			K = K / 10;
		}
		for (; K > 0; K /= 10)
		{
			ans.push_back(K % 10);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

