#include <iostream>
#include <vector>

using namespace std;

class Vector {
	vector<int> v;

	public :
		Vector(int size) {
			v.reserve(size);
			cout << v.size() << endl;
		}
};

int main() {
	Vector vec(3);

	vector<int> v1;
	cout << "v1 : " << v1.size() << endl;
	v1.resize(3);
	cout << "reserve v1 : " << v1.size() << endl;

	return 0;
}
		
