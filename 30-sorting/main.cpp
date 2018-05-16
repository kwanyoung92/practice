#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

int bubble_sort(vector<int> &v) {
	int total_swap = 0;
	for(int i = 0; i < v.size(); i++) {
		int is_swap = 0;
		for(int j = 0; j < v.size() - 1; j++) {
			if(v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
				++is_swap;
				++total_swap;
			}
		}
		if(is_swap == 0)
			break;
	}
	return total_swap;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    // Write Your Code Here
	int swaps = bubble_sort(a);
	cout << "Array is sorted in " << swaps << " swaps." << endl;
	cout << "First Element: " << a.front() << endl;
	cout << "Last Element: " << a.back() << endl;

    return 0;
}
