#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct DoubleListNode
{
	int val,key;
	DoubleListNode* next;
	DoubleListNode* pre;
	DoubleListNode(int key,int val) :key(key),val(val), next(nullptr), pre(nullptr) {};
	DoubleListNode() :next(nullptr), pre(nullptr) {};
};

class LRUCache {
private:
	int capacity,size;
	unordered_map<int, DoubleListNode*> listLRU;
	DoubleListNode* head, * end;
public:
	LRUCache(int capacity) {
		size = 0;
		head = new DoubleListNode();
		end = new DoubleListNode();
		this->capacity = capacity;
		head->next = end;
		end->pre = head;
	}

	int get(int key) {
		if (!listLRU.count(key)) {
			return -1;
		}
		else
		{
			DoubleListNode* node = listLRU[key];
			moveToHead(node);
			return node->val;
		}
		
	}

	void put(int key, int value) {
		if (listLRU.count(key)) {
			listLRU[key]->val = value;
			moveToHead(listLRU[key]);
		}
		else
		{
			DoubleListNode* node = new DoubleListNode(key,value);
			listLRU[key] = node;
			addToHead(node);
			size++;
			if (size > capacity) {
				DoubleListNode* removed = removeEnd();
				listLRU.erase(removed->key);
				delete removed;
				size--;
			}
		}
	}
	void addToHead(DoubleListNode* node) {
		node->next = head->next;
		node->pre = head;
		head->next->pre = node;
		head->next = node;
	}
	void moveToHead(DoubleListNode* node) {
		node->pre->next = node->next;
		node->next->pre = node->pre;
		node->next = head->next;
		node->pre = head;
		head->next->pre = node;
		head->next = node;
	}
	DoubleListNode* removeEnd() {
		DoubleListNode* returns = end->pre;
		returns->pre->next = end;
		end->pre = returns->pre;
		return returns;
	}
};
int main() {
	LRUCache a = LRUCache(2);
	a.put(1, 1);
	a.put(2, 2);
	a.get(1);
	a.put(3, 3);
	a.get(2);
	a.put(4, 4);
	a.get(1);
	a.get(3);
	a.get(4);
}