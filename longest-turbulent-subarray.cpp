#include"headfile.h"
using namespace std;

class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {
		int n = arr.size();
		if(n <= 1){
			return n;
		}
		vector<int> a(n - 1);
		int ans = 1;
		int pre = 0;
		int res = 0;
		for (int i = 0; i < n-1; i++) {
			int cur = 0;
			cur = arr[i] > arr[i + 1] ? 1 : -1;
			if (arr[i] == arr[i + 1]) {
				cur = INT_MAX;
				ans = 0;
				continue;
			}
			if (pre + cur != 0) {
				ans = 1;
				pre = cur;
			}
			else if (pre + cur == 0) {
				ans++;
				pre = cur;
			}
			res = max(res, ans);
		}
		return res + 1;
	}
};
int main() {
	Solution s;
	vector<int> arr({ 9,9});
	s.maxTurbulenceSize(arr);
}