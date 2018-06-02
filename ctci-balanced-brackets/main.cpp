#include <bits/stdc++.h>

using namespace std;

class Stack {
	vector<char> stack;
	int top;

	public :
		Stack(int stack_size) {
			stack.resize(stack_size);
			top = -1;
		}
		bool is_empty();
		bool is_full();
		void push(char data);
		char pop();
};

class Queue {
	vector<char> queue;
	int head;
	int tail;

	public :
		Queue(int queue_size) {
			queue.resize(queue_size);
			head = 0;
			tail = -1;
		}
		bool is_empty();
		bool is_full();
		void enqueue(char data);
		char dequeue();
};

void Stack::push(char data) {
	if(this->is_full()) {
		cout << "size : " << stack.size() << endl;
		cout << "top : " << top << endl;
		cout << "Error: Stack is full. Can't push more data." << endl;
		return;
	}

	++top;
	stack[top] = data;
}

char Stack::pop() {
	if(this->is_empty()) {
		char return_value = stack[top];
		--top;
		return return_value;
	}
	else {
		cout << "Error: Stack is empty. Can't pop any data." << endl;
		return '\0';
	};
}

bool Stack::is_empty() {
	if(top == -1) return true;
	else return false;
}

bool Stack::is_full() {
	if(stack.size() == top) return true;
	else false;
}

void Queue::enqueue(char data) {
	if(this->is_full()) { 
		cout << "Error: Queue is full. Can't enqueue more data." << endl;
		return;
	}

	++tail;
	queue[tail] = data;
}

char Queue::dequeue() {
	if(this->is_empty()) {
		cout << "Error: Queue is empty. Can't dequeue any data." << endl;
		return '\0';
	}
	
	char return_value = queue[head];
	++head;
	return return_value;
}

bool Queue::is_empty() {
	if(tail == -1) return true;
	else return false;
}

bool Queue::is_full() {
	if(queue.size() == tail) return true;
	else false;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<bool> result(t);	// save result;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);

		// find bracket
		int str_length = expression.length();
		Stack s(str_length/2);
		Queue q(str_length/2);

		for(int i = 0; i < str_length; ++i) {
			if(i < str_length / 2) {
				cout << "push data : " << expression[i] << endl;
				s.push(expression[i]);
			}
			else {
				cout << "enqueue data : " << expression[i] << endl;
				q.enqueue(expression[i]);
			}
		}
		
		bool flag = true;
		for(int i = 0; i < str_length / 2; ++i) {
			if(s.pop() != q.dequeue()) {
				flag = false;
				break;
			}
		}
		result.push_back(flag);
    }

	for(int i = 0; i < t; ++i) {
		if(result[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

    return 0;
}
