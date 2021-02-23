#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int max = numbers.size() - 1, min = 0;
		vector<int> ans;
		while (numbers[max] + numbers[min] != target)
		{
			if (numbers[max] + numbers[min] < target) {
				min++;
			}
			else
			{
				max--;
			}
		}
		ans.push_back(min + 1);
		ans.push_back(max + 1);
		return ans;
	}
};

//Ë«Ö¸Õë