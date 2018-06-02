#include <bits/stdc++.h>

using namespace std;

class Node {
	public :
		string data;
		Node* next;
		Node(string str) : data(str), next(NULL) {}
};

vector<string> split_string(string);
void hash_insert(vector<Node*>&, Node*);
bool hash_find(vector<Node*>&, string);
unsigned int x65599(const string);

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string ransom_temp_temp;
    getline(cin, ransom_temp_temp);

    vector<string> ransom_temp = split_string(ransom_temp_temp);

    vector<string> ransom(n);

    for (int i = 0; i < n; i++) {
        string ransom_item = ransom_temp[i];

        ransom[i] = ransom_item;
    }

	vector<Node*> hash(m);
	
	for (int i = 0; i < m; ++i) {
		Node* n = new Node(magazine[i]);
		hash_insert(hash, n);
	}

	for (int i = 0; i < n; ++i) {
		if(!hash_find(hash, ransom[i])) {
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";	
	
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

void hash_insert(vector<Node*> &hash, Node* n) {
	unsigned int hashed_idx = x65599(n->data) % hash.size();
	if(!hash[hashed_idx])		// no collision 
		hash[hashed_idx] = n;
	else {
		Node* tmp = hash[hashed_idx];

		while(tmp->next)
			tmp = tmp->next;

		tmp->next = n;
	}
}

bool hash_find(vector<Node*>& hash, string str) {
	unsigned int hashed_idx = x65599(str) % hash.size();
	if(hash[hashed_idx]) {	// find data
		Node* tmp = hash[hashed_idx];
		if(tmp->data == str) {
			Node* buffer = tmp;
			hash[hashed_idx] = hash[hashed_idx]->next;
			free(buffer);
			return true;
		}
		else {
			while(tmp->next) {
				if(tmp->next->data == str) {
					Node* buffer = tmp->next;
					tmp->next = tmp->next->next;
					free(buffer);
					return true;
				}
				tmp = tmp->next;
			}
		}
	}
	return false;
}

unsigned int x65599(const string str) {
	unsigned int hash = 0;
	for(size_t i = 0; i < str.size(); ++i)
		hash = 65599 * hash + str[i];
	return hash ^ (hash >> 16);
}
