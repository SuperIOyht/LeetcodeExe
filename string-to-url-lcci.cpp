#include"headfile.h"
using namespace std;

class Solution {
public:
	string replaceSpaces(string S, int length) {
		int size = S.size();
		int end = size - 1;
		for (int i = length - 1; i >= 0; --i) {
			if (S[i] == ' ') {
				S[end--] = '0';
				S[end--] = '2';
				S[end--] = '%';
			}
			else
			{
				S[end--] = S[i];
			}
		}
		return S.erase(0, end + 1);
	}
};
