#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

	vector<int> result;

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
		
		int sum = 0;

		for(int i = 3; i < n; i += 3) {
			cout << "3 : " << i << endl;
			sum += i;
		}
		cout << "------------------------------" << endl;
		for(int i = 5; i < n; i += 5) {
			cout << "5 : " << i << endl;
			sum += i;
		}
		cout << "------------------------------" << endl;
		if(n > 15) {
			for(int i = 15; i < n; i += 15) {
				cout << "15 : " << i << endl;
				sum = sum - 15;
			}
		}
		cout << "------------------------------" << endl;
		
		result.push_back(sum);
    }
	
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}

    return 0;
}	
