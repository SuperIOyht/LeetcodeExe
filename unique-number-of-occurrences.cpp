#include"headfile.h"
using namespace std;

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> map, map2;
		for (int it : arr) {
			++map[it];
		}
		for (auto it = map.begin(); it != map.end(); it++)
		{
			if (map2.count(it->second))
			{
				return false;
			}
			else
			{
				++map2[it->second];
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1, 1, 3, 4, 5 };
	s.uniqueOccurrences(a);
}