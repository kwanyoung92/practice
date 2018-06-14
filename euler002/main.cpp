#include <iostream>
#include <vector>

using namespace std;

unsigned long long fib_even(vector<unsigned long long> &memo, long n);

int main(){
	vector<unsigned long long> result;
	vector<unsigned long long> fib_even_array;

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
		cout << fib_even(fib_even_array, n) << endl;
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
