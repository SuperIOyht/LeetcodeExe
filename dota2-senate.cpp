#include"headfile.h"
using namespace std;
class Solution {
public:
	string predictPartyVictory(string senate) {
		queue<int> radiant, dire;
		int n = senate.size();
		for (int i = 0; i < senate.size(); i++)
		{
			if (senate[i] == 'R')
			{
				radiant.push(i);
			}
			else
			{
				dire.push(i);
			}
		}
		while (!dire.empty() && !radiant.empty())
		{
			if (dire.front() < radiant.front())
			{
				int temp = dire.front();
				dire.pop();
				dire.push(temp + n);
				radiant.pop();
			}
			else
			{
				int temp = radiant.front();
				radiant.pop();
				radiant.push(temp + n);
				dire.pop();
			}
		}
		return dire.empty() ? "Radiant" : "Dire";
	}
};

int main() {
	Solution s;
	s.predictPartyVictory("RDD");
}