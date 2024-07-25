#include"headfile.h"
using namespace std;
class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		for (int i = 0; i < bits.size(); ++i) {
			if (i == bits.size() - 1 && bits[i] == 0) {
				return true;
			}
			if (bits[i] == 0) {
				continue;
			}
			if (bits[i] == 1) {
				i++;
				continue;
			}
		}
		return false;
	}
};