#include"headfile.h"
using namespace std;

int mpartition(vector<int>& nums, int left, int right) {
	int i = left, j = right + 1;
	int p = nums[left];
	while (true)
	{
		while (nums[++i] < p && i != right)
		{
		}
		while (nums[--j] > p && j != left)
		{
		}
		if (i >= j) {
			break;
		}
		swap(nums[i], nums[j]);
	}
	swap(left, j);
	return j;
}

void quick_sort(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int j = mpartition(nums, left, right);
	quick_sort(nums, left, j - 1);
	quick_sort(nums, j + 1, right);
}

int main() {
	vector<int> a({ 3,1,6,2,5,8,4,7 });
	quick_sort(a, 0, a.size() - 1);
}

