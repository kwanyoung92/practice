#include <iostream>
#include <vector>

using namespace std;

unsigned long long fib_even(vector<unsigned long long> &memo, long n);
void cal_fib_even(vector<unsigned long long> &result, vector<unsigned long long> &fib_even_array, long n);

int main(){
	vector<unsigned long long> result;
	vector<unsigned long long> fib_even_array;
	fib_even_array.push_back(0);
	fib_even_array.push_back(2);
	
	fib_even_array.resize(3);
	cout << fib_even(fib_even_array, 0) << endl;
	cout << fib_even(fib_even_array, 1) << endl;
	cout << fib_even(fib_even_array, 2) << endl;

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;

		fib_even_array.resize(n);
		cal_fib_even(result, fib_even_array, n);
    }
	for(int i = 0; i < t; ++i) {
		cout << result[i] << endl;
	}
    return 0;
}

unsigned long long fib_even(vector<unsigned long long> &memo, long n) {
	if(n <= 0) return 0;
	else if (n == 1) return 2;
	else if (memo[n] > 0) return memo[n];
	memo.push_back(4 * fib_even(memo, n - 1) + fib_even(memo, n - 2));
	return memo[n];
}

void cal_fib_even(vector<unsigned long long> &result, vector<unsigned long long> &memo, long n) {
	unsigned long long sum = 0;

	for(long i = 0; i < n; ++i) {
		if(fib_even(memo, i) > n) {
			break;
		}
		else {
			sum += fib_even(memo, i);
		}
	}

	result.push_back(sum);
}
