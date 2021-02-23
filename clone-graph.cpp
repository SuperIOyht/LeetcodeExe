#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

/*
class Solution {
public:
	Node* cloneGraph(Node* node) {
		Node* ans = new Node(node->val);
		vector<Node*> set(100,0);
		if (node->neighbors.empty())
		{
			return ans;
		}

		stack<Node*> as;
		stack<Node*> ns;
		as.push(ans);
		ns.push(node);
		Node* temp = new Node();
		Node* tempa = new Node();

		while (!ns.empty())
		{
			temp = ns.top();
			ns.pop();
			tempa = as.top();
			as.pop();
			for (int i = 0; i < temp->neighbors.size(); i++) {
				if (set[temp->neighbors[i]->val - 1] == nullptr) {
					set[temp->neighbors[i]->val - 1] = new Node(temp->neighbors[i]->val);
				}
				tempa->neighbors.push_back(set[temp->neighbors[i]->val - 1]);
				if (set[temp->neighbors[i]->val - 1]->neighbors.empty()) {
					as.push(set[temp->neighbors[i]->val - 1]);
					ns.push(temp->neighbors[i]);
				}
			}
		}
		return ans;
	}
};
*/

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr)
		{
			return nullptr;
		}
		Node* ans = new Node(node->val);
		vector<Node*> set(100, 0);
		set[node->val - 1] = ans;
		stack<Node*> as;
		stack<Node*> ns;
		as.push(ans);
		ns.push(node);
		Node* temp = new Node();
		Node* tempa = new Node();

		while (!ns.empty())
		{
			temp = ns.top();
			ns.pop();
			tempa = as.top();
			as.pop();
			for (int i = 0; i < temp->neighbors.size(); i++) {
				if (set[temp->neighbors[i]->val - 1] == nullptr) {
					set[temp->neighbors[i]->val - 1] = new Node(temp->neighbors[i]->val);
					as.push(set[temp->neighbors[i]->val - 1]);
					ns.push(temp->neighbors[i]);
				}
				tempa->neighbors.push_back(set[temp->neighbors[i]->val - 1]);
			}
		}
		return ans;
	}
};

int main() {
	Node* a = new Node(1);
	Node* b = new Node(2);
	a->neighbors.push_back(b);
	b->neighbors.push_back(a);
	Solution s;
	s.cloneGraph(a);
	return 0;
}