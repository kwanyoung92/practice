#include <bits/stdc++.h>
#define MAX 100001 

using namespace std;

vector<string> split_string(string);

// Complete the minuteToWinIt function below.
int minuteToWinIt(vector<int> a, int k) {
    // Return the minimum amount of time in minutes.

	int min_consecutive = MAX, tmp_consecutive = 0;
	int start_idx = 0, finish_idx = 0;

	for(int i = 0; i < a.size(); ++i) {
		if(a[i-1] + k == a[i]) {
			++tmp_consecutive;
		}
		else {
			if(tmp_consecutive != 0 && tmp_consecutive < min_consecutive) {
				finish_idx = i - 1;
				if(tmp_consecutive == 1) {	// case 3
					start_idx = i - 1;
				}
				else {	//case 1
					start_idx = i - 1 - tmp_consecutive;
				}
				min_consecutive = tmp_consecutive;
				tmp_consecutive = 0;
			}
		}
		if(i == a.size() - 1) {	// case 2, 4
			if(min_consecutive != MAX) {
				finish_idx = i;
				start_idx = i - tmp_consecutive;
			}
		}
	}

	int minutes = 0;
	for(int i = start_idx; i >= 1; --i) {
		if(a[i-1] + k != a[i]) {
			++minutes;
			a[i-1] = a[i] - abs(k);
		}
	}

	for(int i = finish_idx; i < a.size(); ++i) {
		if(a[i-1] + k != a[i]) {
			++minutes;
			a[i] = a[i-1] + k;	
		}
	}

	return minutes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minuteToWinIt(a, k);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

