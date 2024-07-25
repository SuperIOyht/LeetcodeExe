#include"headfile.h"
using namespace std;

class A {};
class B {};

int main() {
	A* pta = new A;
	cout << pta << endl;
	
	B* ptb = reinterpret_cast<B*>(pta);
	
	cout << ptb << endl;

	int* a = reinterpret_cast<int*>(ptb);
	cout << a << endl;
}