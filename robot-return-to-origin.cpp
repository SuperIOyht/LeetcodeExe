#include"headfile.h"
using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int x = 0, y = 0;
		for (auto& it : moves) {
			switch (it)
			{
			case 'U': {++y; break; }
			case 'D': { --y; break; }
			case 'R': {--x; break; }
			case 'L': {++x; break; }
			}
		}
		return x == 0 && y == 0;
	}
};

int main() {
	Solution s;
	s.judgeCircle("UDRL");
}