#include"headfile.h"
using namespace std;
/*
void maxHeapify(vector<int>& a, int i, int heapSize) {
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;
	if (left < heapSize && a[left] > a[i]) {
		largest = left;
	}
	if (right < heapSize && a[right] < a[i]) {
		largest = right;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		maxHeapify(a, largest, heapSize);
	}
}

void buildMaxHeap(vector<int>& a, int heapSize) {
	for (int i = heapSize / 2; i >= 0; --i) {
		maxHeapify(a, i, heapSize);
	}
}

*/

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

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int size = nums.size();
		build_max_heap(nums, size);
		for (int i = nums.size() - 1; i > nums.size() - k; --i) {
			swap(nums[0], nums[i]);
			--size;
			build_max_heap(nums, size);
		}
		return nums[0];
	}
};