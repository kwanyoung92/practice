#include <iostream>
#include <string>
using namespace std;

class Parent {
	private :
		string s;
	public :
		Parent() : s("부모")
		{
			cout << "부모 클래스" << endl;
		}
		
		void what() { cout << s << endl; }
};

class Child : public Parent {
	private :
		string s;
	public :
		Child() : s("자식")
		{
			cout << "자식 클래스" << endl;
		}

		void what() { cout << s << endl;}

};

int main() {
	Parent p;
	Child c;
	Parent* p_ptr;	// Up casting
//	Child* c_ptr = &p;	// Down casting	

	p_ptr = &c;

	p_ptr->what();
	return 0;
}
