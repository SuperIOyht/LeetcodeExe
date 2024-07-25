#include"headfile.h"
using namespace std;

class Solution {
public:
	string compressString(string S) {
		string temp;
		char now = S[0];
		int count = 1;
		for (int i = 1; i < S.size(); ++i) {
			if (S[i] == now) {
				count++;
			}
			else {
				temp.push_back(now);
				temp.append(to_string(count));
				count = 1;
				now = S[i];
			}
		}
		temp.push_back(now);
		temp.append(to_string(count));
		return S.size() > temp.size() ? temp : S;
	}
};
