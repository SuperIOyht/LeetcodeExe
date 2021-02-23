#include"headfile.h"
using namespace std;

class MedianFinder {
private:
	priority_queue<int> small;
	priority_queue<int, vector<int>, greater<int>> large;
	int smallSize, largeSize;
public:
	/** initialize your data structure here. */
	MedianFinder() :smallSize(0), largeSize(0){

	}
	void makeBalance() {
		if (smallSize > largeSize + 1) {
			large.push(small.top());
			small.pop();
			--smallSize;
			++largeSize;
		}
		else if (largeSize > smallSize) {
			small.push(large.top());
			large.pop();
			++smallSize;
			--largeSize;
		}
	}
	void addNum(int num) {
		if (small.empty() || num <= small.top()) {
			small.push(num);
			++smallSize;
		}
		else
		{
			large.push(num);
			++largeSize;
		}
		makeBalance();
	}

	double findMedian() {
		if (smallSize + largeSize == 0) {
			return 0;
		}
		else if(smallSize + largeSize == 1)
		{
			return small.top();
		}
		return (smallSize + largeSize) & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
	MedianFinder* obj = new MedianFinder();
	obj->findMedian();
	obj->addNum(1);
	obj->findMedian();
	obj->addNum(2);
	obj->findMedian();
	obj->addNum(3);
	obj->findMedian();
	double param_2 = obj->findMedian();
}