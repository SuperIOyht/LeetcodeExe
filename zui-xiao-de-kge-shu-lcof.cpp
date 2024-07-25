#include"headfile.h"
using namespace std;


class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < arr.size(); i++) {
			pq.push(arr[i]);
		}
		vector<int> result;
		for (int i = 0; i < k; ++i) {
			result.push_back(pq.top());
			pq.pop();
		}
	}
};