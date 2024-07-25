#include"headfile.h"
using namespace std;
class Solution {
public:
	bool isUnique(string astr) {
		int mark = 0;
		for (int i = 0; i < astr.size(); ++i) {
			int offset = astr[i] - 'a';
			if (mark & (1 << offset)) {
				return false;
			}
			else
			{
				mark |= 1 << offset;
			}
		}
		return true;
	}
};
