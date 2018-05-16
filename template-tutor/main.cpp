#include <iostream>
using namespace std;

template<typename T>
class Tem {
	private :
		T var;
	public :
		Tem(T var) : var(var) {}

		void print() {
			cout << var << endl;
		}
};

int main() {
	Tem<int> tmp_int(3);
	Tem<char> tmp_string('w');

	tmp_int.print();
	tmp_string.print();

	return 0;
}
