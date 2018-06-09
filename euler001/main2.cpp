#include <iostream>
#include <vector>

#define N 1000

using namespace std;


int main() {
	vector<int> mul_table(N);

	int sum = 0;

	for(int i = 0; i < N; ++i) {
		if(i == 0) {
			mul_table[i] = 0;
		}
		else if(i % 3 == 0) {
			sum += i;
			mul_table[i] = sum;
		}
		else if(i % 5 == 0) {
			sum += i;
			mul_table[i] = sum;
		}
		else {
			mul_table[i] = 0;
		}
	}

	for(int i = 0; i < 100; ++i) {
		if(mul_table[i] != 0) {
			cout << i << ": " << mul_table[i] << endl;
		}
	}
	
	return 0;
}
