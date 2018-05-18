#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> set_array;
	vector<int> less_array;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);
		
		set_array.push_back(n);
		less_array.push_back(k);
    }

	for(int i = 0; i < set_array.size(); i++) {
		int max = -1;
		for(int j = 1; j <= set_array[i] - 1; j++) {
			for(int k = j+1; k <= set_array[i]; k++) {
				int bitwise_result = -1;
				bitwise_result = j & k;
				if(bitwise_result < less_array[i] && bitwise_result > max)
					max = bitwise_result;
			}
		}
		cout << max << endl;
	}

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
