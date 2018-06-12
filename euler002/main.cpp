#include <iostream>
#include <vector>

using namespace std;

long long fib_cal(long n);
long long fib(long n, long long *memo);

int main(){
	vector<long long> result;

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
		cout << "Fib value : " << fib_cal(n) << endl;
		result.push_back(fib_cal(n));
    }
	for(int i = 0; i < t; ++i) {
		cout << result[i] << endl;
	}
    return 0;
}

long long fib_cal(long n) {
	long long sum = 0;
	long long *memo = new long long [n+1];
	for(long i = 0; i < n; ++i) {
		long long tmp_fib = fib(i, memo);
		if(tmp_fib % 2 == 0) {
			sum += tmp_fib;
		}
	}
	return sum;
}

long long fib(long n, long long *memo) {
	if(n <= 0) return 0;
	else if (n == 1) return 1;
	else if (memo[n] > 0) return memo[n];

	memo[n] = fib(n-1, memo) + fib(n-2, memo);
	return memo[n];
}
