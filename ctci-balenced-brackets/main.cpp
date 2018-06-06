#include <bits/stdc++.h>

using namespace std;

class Bracket {
    char bracket;
    public :
        Bracket(char bracket) : bracket(bracket) {}
        char get_data() {
            return bracket;
        }
        char find_pair_bracket() {
            switch(bracket) {
                case '(' :
                    return ')';
                case '{' :
                    return '}';
                case '[' :
                    return ']';
                default :
                    return '\0';
            }
        }
        bool is_open_bracket() {
            switch(bracket) {
                case '(' : case '{' : case '[' :
                    return true;
                default :
                    return false;
            }
        }
};

int main()
{
    stack<char> bracket_stack;
    vector<bool> result_vector;
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);
           
        int str_length = expression.size();
        bool flag = true;
        for(int i = 0; i < str_length; ++i) {
            Bracket b(expression[i]);
            if(i == 0 && !b.is_open_bracket()) {
                flag = false;
                break;
            } 
            else {
                if(b.is_open_bracket()) {
                    bracket_stack.push(b.get_data()); 
                }    
                else {
                    if(!bracket_stack.empty()) {
                        if(bracket_stack.top() == b.find_pair_bracket())
                            bracket_stack.pop();
                        else {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        result_vector.push_back(flag);
    }
    
    for(int i = 0; i < result_vector.size(); ++i) {
        if(result_vector[i]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

