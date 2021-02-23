#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
class Solution {
public:
	int binaryGap(int N) {
		int last = -1;
		int ans = 0,cnt =0;
		while (N)
		{
			if (N & 1) {
				if (last >= 0) {
					ans = max(ans, cnt - last);
				}
				last = cnt;
			}
			N >>= 1;
			cnt++;
		}
		return ans;
	}
};