#include"headfile.h"
using namespace std;

int main() {
	vector<int> a, b;
	int tempa, tempb;
	cin >> tempa >> tempb;
	while (tempa != 0 && tempb != 0)
	{
		a.push_back(tempa);
		b.push_back(tempb);
		cin >> tempa >> tempb;
	}
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] + b[i] << endl;
	}
}