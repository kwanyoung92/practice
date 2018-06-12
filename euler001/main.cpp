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

long long cal_sum(int base, int n) {
	int max_base = 0;

	for(int i = n - 1; i >= base; --i) {
		if(i % base == 0) { 
			max_base = i;
			break;
		}
	}
	long long div = ((n - 1) / base);

	long long sum = (div*(base + max_base)) / 2;
	return sum;
}


int main(){
    int t;
    cin >> t;
	
	vector<long long> result;

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
		result.push_back(cal_sum(3, n) + cal_sum(5, n) - cal_sum(15, n));
    }

	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
    return 0;
}
