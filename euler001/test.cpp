#include <iostream>
#include <vector>

using namespace std;

typedef struct mul {
	int n;
	int sum;
}mul;

int main() {
	vector<mul> result;
	mul x, y;

	x.n = 2;
	y.n = 3;

	result.push_back(x);
	result.push_back(y);

	cout << result[0].n << endl;
	cout << result[1].n << endl;


	return 0;
}
