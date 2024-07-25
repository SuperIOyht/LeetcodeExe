#include"headfile.h"
using namespace std;


class Solution {
public:
	void heapify(vector<int>& a, int i, int heapSize) {
		int left = i * 2 + 1;
		int right = i * 2 + 2;
		int largest = i;
		if (left < heapSize && a[largest] < a[left]) {
			largest = left;
		}
		if (right < heapSize && a[largest] < a[right]) {
			largest = right;
		}
		if (largest != i) {
			swap(a[i], a[largest]);
			heapify(a, largest, heapSize);
		}
	}
	void build_max_heap(vector<int>&a, int heapSize) {
		for (int i = heapSize / 2; i >= 0; --i) {
			heapify(a, i, heapSize);
		}
	}
	void quick_sort(vector<int>&a, int left, int right) {
		if (left >= right) {
			return;
		}
		int mid = partition(a, left, right);
		quick_sort(a, left, mid - 1);
		quick_sort(a, mid + 1, right);
	}
	int partition(vector<int>& a, int left, int right) {
		int leftPointer = left;
		int rightPointer = right + 1;
		int num = a[left];
		while (true )
		{
			while (a[++leftPointer] > num && leftPointer != right)
			{

			}
			while (a[--rightPointer] < num&& rightPointer != left)
			{

			}
			if (rightPointer <= leftPointer) {
				break;
			}
			swap(a[leftPointer], a[rightPointer]);
		}
		swap(a[rightPointer], a[left]);
		return rightPointer;
	}
	int findKthLargest(vector<int>& nums, int k) {
		//int size = nums.size();
		//build_max_heap(nums, size);
		//for (int i = nums.size() - 1; i > nums.size() - k; --i) {
		//	swap(nums[0], nums[i]);
		//	--size;
		//	heapify(nums, 0, size);
		//}
		//return nums[0];
		quick_sort(nums, 0, nums.size() - 1);
		return nums[k - 1];
	}
};

int main() {
	Solution s;
	vector<int> arr({ 3,2,3,1,2,4,5,5,6 });
	s.findKthLargest(arr, 4);
}