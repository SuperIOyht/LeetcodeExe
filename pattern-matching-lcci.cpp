#include"headfile.h"
using namespace std;

class Solution {
public:
	bool patternMatching(string pattern, string value) {
		bool ans = false;
		char a = pattern[0];
		int sizeA = 0, sizeB = 0;
		for (auto it : pattern) {
			if (it == a) {
				++sizeA;
			}
			else
			{
				++sizeB;
			}
		}
		int sizeV = value.size();
		if (value =="" && sizeA != 0 && sizeB != 0) {
			return false;
		}

		for (int i = 0; i <= sizeV / sizeA; i++) {
			bool paseBool = true;
			int aLen = 0;
			int bLen = 0;
			if (sizeB != 0) {
				bLen = (sizeV - i * sizeA) / sizeB;
			}
			if ((sizeV - bLen * sizeB) / sizeA != i) {
				continue;
			}
			if ((sizeV - i * sizeA) % sizeB != 0) {
				continue;
			}
			aLen = (sizeV - bLen * sizeB) / sizeA;
			int pos = 0;
			string tempA, tempB;
			for (auto it : pattern) {
				if (it == a) {
					if (tempA.empty()) {
						tempA = value.substr(pos, aLen);
					}
					else if(tempA != value.substr(pos, aLen) || tempA == tempB)
					{
						pos += aLen;
						paseBool = false;
						break;
					}
					pos += aLen;
				}
				else
				{
					if (tempB.empty()) {
						tempB = value.substr(pos, bLen);
					}
					else if (tempB != value.substr(pos, bLen) || tempA == tempB)
					{
						pos += bLen;
						paseBool = false;
						break;
					}
					pos += bLen;
				}
			}
			if (paseBool) {
				ans = paseBool;
				return ans;
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.patternMatching("aaaa",
		"dogcatcatdog");
	return 0;
}