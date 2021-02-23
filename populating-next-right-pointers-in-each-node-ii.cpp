#include"headfile.h"
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr) {
			return root;
		}
		queue<Node*> queNode;
		queNode.push(root);
		while (!queNode.empty())
		{
			Node* temp = nullptr;
			Node* now;
			int size = queNode.size();
			for (int i = 0; i < size; i++) {
				now = queNode.front();
				queNode.pop();
				now->next = temp;
				if (now->right != nullptr) {
					queNode.push(now->right);
				}
				if (now->left != nullptr) {
					queNode.push(now->left);
				}
				temp = now;
			}
		}
		return root;
	}
};

int main() {
	//Node* a = new Node(1);
	//Node* b = new Node(2);
	//Node* c = new Node(3);
	//Node* d = new Node(4);
	//Node* e = new Node(5);
	//Node* f = new Node(7);
	//a->left = b;
	//a->right = c;
	//b->left = d;
	//b->right = e;
	//c->right = f;
	Node* a = nullptr;
	Solution s;
	s.connect(a);
}