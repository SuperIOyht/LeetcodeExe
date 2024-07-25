#include"headfile.h"
using namespace std;

class Solution {
public:
	bool oneEditAway(string first, string second) {
		int size_1 = first.size();
		int size_2 = second.size();
		if (abs(size_1 - size_2) > 1) {
			return false;
		}
		if (size_1 < size_2) {
			return oneEditAway(second, first);
		}
		int flag = 0;
		if (size_1 == size_2) {
			for (int i = 0; i < size_1; ++i) {
				if (first[i] != second[i]) {
					flag++;
				}
			}
			return flag <= 1;
		}
		else
		{
			int point1 = 0, point2 = 0;
			while (point1 < size_1)
			{
				if (first[point1] == second[point2]) {
					point1++;
					point2++;
				}
				else
				{
					point1++;
					flag++;
				}
			}
			return flag <= 1;
		}
	}
};
