#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int left = 0, right = numbers.size()-1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (numbers[mid] < numbers[right])
			{
				right = mid;
			}
			else if (numbers[mid] > numbers[right])
			{
				left = mid + 1;
			}
			else
			{
				right--;
			}
		}
		return numbers[left];
	}
};
int main() {
	Solution s;
	vector<int> a = { 2,2,2,0,1 };
	s.minArray(a);
	return 0;
}