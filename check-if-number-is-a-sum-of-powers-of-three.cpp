#include"headfile.h"
using namespace std;

class Solution {
public:
	bool checkPowersOfThree(int n) {
		set<int> mset;
		while (n != 0)
		{
			int a = log(n) / log(3);
			n -= pow(3, a);
			if (mset.count(a)) {
				return false;
			}
			mset.emplace(a);
		}
		return true;
	}
};

