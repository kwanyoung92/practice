#include <iostream>

using namespace std;

int main() {
	for(int i = 0; i < 20; ++i) {
		if(i % 3 == 0) {
			cout << i << ": " << '3' << endl;
		}
		else if(i % 5 == 0) {
			cout << i << ": " << '5' << endl;
		}
	}
	return 0;
}
