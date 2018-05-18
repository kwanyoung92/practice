#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define POSITIVE_MESSAGE "Prime"
#define NEGATIVE_MESSAGE "Not prime"

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int T = 0;
	cin >> T;

	vector<int> n;

	for(int i = 0; i < T; i++) {
		int number = 0;
		cin >> number;
		n.push_back(number);	
	}

	for(int i = 0; i < T; i++) {
		int is_prime = 1, divide_number = 2;
	 
		do {
			if(n[i] == 2) break;
			if(n[i] == 1 || n[i] % divide_number == 0) {
				is_prime = false;
				break;
			}
			++divide_number;
		} while(divide_number <= sqrt(n[i]));

		if(is_prime) cout << POSITIVE_MESSAGE << endl;
		else cout << NEGATIVE_MESSAGE << endl;
	}

    return 0;
}
