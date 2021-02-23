#include"headfile.h"
using namespace std;

class KthLargest {
public:
	priority_queue<int, vector<int>, greater<int>> que;
	int size;
	KthLargest(int k, vector<int>& nums) {
		this->size = k;
		for (auto &it : nums) {
			this->add(it);
		}
	}

	int add(int val) {
		que.push(val);
		if (que.size() > size) {
			que.pop();
		}
		return que.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */