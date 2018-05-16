#include <iostream>
#include <string.h>
using namespace std;

class DeepCopy {
	private :
		int number;
		char* name;
	public :
		DeepCopy(int input_number, char* input_name);	// constructor
		DeepCopy(const DeepCopy &d);
		void print();
};

DeepCopy::DeepCopy(int input_number, char* input_name) {
	number = input_number;
	name = new char[strlen(input_name)+1];
	strcpy(name, input_name);
}

DeepCopy::DeepCopy(const DeepCopy &d) {
	number = d.number;
	name = new char[strlen(d.name)+1];
	strcpy(name, d.name);
}

void DeepCopy::print() {
	cout << "Number : " << number << endl;
	cout << "Name : " << name << endl;
}

int main() {
	DeepCopy depy(3, "Hi");
	depy.print();

	DeepCopy depy2(depy);
	depy2.print();

	return 0;
}
