#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;

	try {
		cout << stoi(S, nullptr, 10);
	}
	catch(...) {
		cout << "Bad String";
	}

	return 0;
}
