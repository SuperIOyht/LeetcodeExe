#include"headfile.h"
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(),g.end());
		sort(s.begin(), s.end());
		int Gpoint = 0, sPoint = 0;
		int res = 0;
		while (Gpoint < g.size() && sPoint < s.size())
		{
			if (g[Gpoint] <= s[sPoint])
			{
				++res;
				++Gpoint;
				++sPoint;
			}
			else
			{
				++sPoint;
			}
		}
		return res;
	}
};