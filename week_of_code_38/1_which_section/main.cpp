#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the whichSection function below.
int whichSection(int n, int k, vector<int> a) {
    // Return the section number you will be assigned to assuming you are student number k.
	// Brute case - O(n)
	int front = 1;
	int last = a[0];
	int section = 1;
	for(int i = 0; i < a.size(); ++i) {
		if(k >= front && k <= last) {
			return section;
		}
		else {
			front = last + 1;
			last = a[i+1] + last;
			++section;
		}
	}
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nkm_temp;
        getline(cin, nkm_temp);

        vector<string> nkm = split_string(nkm_temp);

        int n = stoi(nkm[0]);

        int k = stoi(nkm[1]);

        int m = stoi(nkm[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(m);

        for (int i = 0; i < m; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = whichSection(n, k, a);

        fout << result << "\n";
    }

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
