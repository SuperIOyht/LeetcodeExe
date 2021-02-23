#include"headfile.h"
using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int five = 0, ten = 0;
		for (int it : bills) {
			if (it == 5)
			{
				five++;
			}
			else if (it == 10)
			{
				five--;
				ten++;
			}
			else if (it == 20)
			{
				five--;
				if (ten > 0)
				{
					ten--;
				}
				else
				{
					five-=2;
				}
			}
			if (five < 0 || ten < 0)
			{
				return false;
			}
		}
		return true;
	}
};