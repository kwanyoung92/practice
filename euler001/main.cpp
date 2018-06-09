#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct multiples {
	int n;
	int sum;
}multiples;

int main(){
    int t;
    cin >> t;
	
	vector<multiples> result;

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

		int start = 3;
		int sum = 0;

		if(!result.empty()) {
			for(int i = 0; i < result.size(); ++i) {
				if(start < result[i].n && start < n) {
					start = result[i].n;
					sum = result[i].sum;
				}
			}
		}

		for(int i = start; i < n; ++i) {
			if(i % 3 == 0) {
				sum += i;
			}
			else if(i % 5 == 0) {
				sum += i;
			}
		}
		multiples result_mul;
		result_mul.n = start;
		result_mul.sum = sum;
		result.push_back(result_mul);
    }

	for(int i = 0; i < result.size(); ++i) {
		cout << result[i].sum << endl;
	}

    return 0;
}
