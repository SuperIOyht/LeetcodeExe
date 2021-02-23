#include"headfile.h"
using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) {
			return 0;
		}
		vector<int> temp(size);
		return itotator(nums, temp, 0, size - 1);
	}
	int itotator(vector<int>& nums, vector<int>temp, int left, int right) {
		if (left == right) {
			return 0;
		}
		int mid = left + (right - left) / 2;
		int leftPairs = itotator(nums, temp, left, mid);
		int rightPairs = itotator(nums, temp, mid + 1, right);
		int thisPairs = mergeSort(nums, temp, left, right, mid);
		return leftPairs + rightPairs + thisPairs;
	}
	int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right,int mid) {
		
		for (int i = left; i <= right; i++) {
			temp[i] = nums[i];
		}
		int i = left;
		int j = right;
		int count = 0;
		for (int k = left; k <= right; k++) {
			if (i == mid + 1) {
				nums[k] = temp[j];
				j++;
			}
			else if (j == right + 1) {
				nums[k] = temp[i];
				i++;
			}
			else if (temp[i] <= temp[j]) {
				nums[k] == temp[i];
				i++;
			}
			else
			{
				nums[k] == temp[k];
				j++;
				count += mid - i + 1;
			}
		}
		return count;
	}
};

int main() {
	vector<int> a = { 7,5,6,4 };
	Solution s;
	s.reversePairs(a);
}