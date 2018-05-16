#include <iostream>
using namespace std;

class Parent {
	public :
		Parent() {
			cout << "Parent constructor" << endl;
		}
		virtual ~Parent() {
			cout << "Parent distructor" << endl;
		}
};

class Child : public Parent {
	public :
		Child() {
			cout << "Child constructor" << endl;
		}
		~Child() {
			cout << "Child distructor" << endl;
		}
};

int main() {
	Parent *c = new Child();
	delete c;

	return 0;
}
