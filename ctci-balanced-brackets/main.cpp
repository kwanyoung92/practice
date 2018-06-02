#include <bits/stdc++.h>

using namespace std;

class Stack {
    vector<char> stack;
    int top;
    public :
        Stack(int stack_size) : top(-1) {
            stack.resize(stack_size); 
        }
        bool is_full();
        bool is_empty();
        void push(char data);
        char pop();
};

bool Stack::is_full() {
    if(stack.size() == (top+1))
        return true;
    else
        return false;
}

bool Stack::is_empty() {
    if(top == -1)
        return true;
    else
        return false;
}

void Stack::push(char data) {
    if(this->is_full()) {
        return; 
    }
    else {
        ++top;
        stack[top] = data;
    }
}

char Stack::pop() {
    if(this->is_empty()) {
        return '\0';
    } 
    else {
        char pop_data = stack[top];
        --top;
        return pop_data;
    }
}

bool is_open_bracket(char bracket) {
    switch(bracket) {
        case '(' : case '[' : case '{' :
            return true;    
    }
    return false;
}

char return_couple_bracket(char bracket) {
    switch(bracket) {
        case ')' :
            return '(';
        case '}' :
            return '{';
        case ']' :
            return '[';
    } 
    return '\0';
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<bool> result; 
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);
        
        int str_length = expression.size();
        Stack bracket_stack(str_length);        
        
        bool flag = true;
        for(int i = 0; i < str_length; ++i) {
            if(is_open_bracket(expression[i])) {
                bracket_stack.push(expression[i]);
            }
            else {
                if(bracket_stack.pop() != return_couple_bracket(expression[i])) {
                    flag = false;
                    break;
                }
                bracket_stack.pop();
            }
        }
        result.push_back(flag);
    }
    
    for(int i = 0; i < result.size(); ++i) {
        if(result[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

