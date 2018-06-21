#include <bits/stdc++.h>
#define MAX_NUM 100001

using namespace std;

vector<string> split_string(string);

// Complete the minuteToWinIt function below.
int minuteToWinIt(vector<int> a, int k) {
    // Return the minimum amount of time in minutes.

	// Find minimum amount of time in minutes index.
	vector<int> sub_arr(a.size() - 1);

	for(int i = 0; i < sub_arr.size(); ++i) {
		sub_arr[i] = a[i+1] - a[i];
	}

	int consecutive_k = MAX_NUM;
	int consecutive_tmp = 0;

	int start_idx = 0;
	int finish_idx = a.size();

	for(int i = 0; i < sub_arr.size(); ++i) {
		if(sub_arr[i] == k) {
			++consecutive_tmp;
		}
		else {
			if(consecutive_tmp < consecutive_k) {
				consecutive_k = consecutive_tmp;
				finish_idx = i;
				start_idx = i - consecutive_tmp - 1;
				consecutive_tmp = 0;
			}
		}

		if(i == (sub_arr.size() - 1)) {
			if(consecutive_tmp < consecutive_k) {
				consecutive_k = consecutive_tmp;
				finish_idx = i + 1;
				start_idx = i - consecutive_tmp;
				consecutive_tmp = 0;
			}
		}
	}
	cout << "start_idx : " << start_idx << endl;
	cout << "finish_idx : " << finish_idx << endl;
	
	return 0;
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
