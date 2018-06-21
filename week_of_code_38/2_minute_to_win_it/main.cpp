#include <bits/stdc++.h>
#define MAX_NUM 100001

using namespace std;

vector<string> split_string(string);

// Complete the minuteToWinIt function below.
int minuteToWinIt(vector<int> a, int k) {
    // Return the minimum amount of time in minutes.
	int min = MAX_NUM;

	for(int i = 1; i < a.size(); ++i) {
		int minutes = 0;

		for(int j = i; j < a.size(); ++j) {
			if(a[i-1] + k != a[i]) {
				a[i] = a[i-1] + k;
				++minutes;
			}
		}
		for(int j = i; j >= 1; --j) {
			if(a[i] - abs(k) != a[i-1]) {
				a[i-1] = a[i] - abs(k);
				++minutes;
			}
		}

		if(min > minutes) {
			min = minutes;
		}
	}
	
	return min;
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

