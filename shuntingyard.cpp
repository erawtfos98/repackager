#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <unordered_map>

using namespace std;

unordered_map<char,int> operators = {
	{')', 3},
	{'(', 3},
	{'/', 2},
	{'*', 2},
	{'+', 1},
	{'-', 1} };

int shuntingyard2RPN(char *s) {
	stack<char> ops;
	queue<char> output;
	int i = 0;
	while (s[i] != '\0') {
		// whitespace, please ignore
		if (s[i] == ' ') {
			i++;
		}
		// it is an number:
		if ( (operators.find(s[i]) == operators.end())) {
			//cout << "PUSHING: " << s[i] << " TO OPQ" << endl;
			// add to output queue
			//cout << " I AM: " << s[i] << endl;
			output.push(s[i]);
			i++;
		}
		if (s[i] == '(') {
			//cout << s[i] << endl;
			i++;
		}
		if (s[i] == ')') {
			//cout << s[i] << endl;
			i++;
		}
		// it is an operator:
		if (operators.find(s[i]) != operators.end() ) {
			//cout << s[i] << ": " << operators[s[i]] << " " << ops.top() << ": " << operators[ops.top()] << endl;
			while (!ops.empty() && (operators[s[i]] <= operators[ops.top()]) ) {
				//cout << s[i] << ": " << operators[s[i]] << " " << ops.top() << ": " << operators[ops.top()] << endl;
				//cout << "PUSHING: " << ops.top() << " " << "onto OPSTACK." << endl;
				output.push(ops.top());
				ops.pop();
			}
			ops.push(s[i]);
			i++;
		}
	}

	// while there are still tokens on the stack:
	while (!ops.empty()) {
		//cout << ops.top() << endl;
		output.push(ops.top());
		ops.pop();
	}


	//output queue is my "input stack"
	stack<char> result;
	while (!output.empty()) {
		//cout << output.front() << endl;
		// is an operator:
		if (operators.find(output.front()) != operators.end()) {
			int left, right, sum;
			right = result.top() - '0';
			result.pop();
			left = result.top() - '0';
			result.pop();

			cout << "left is: " << left << " " << "right is: " << right << endl;
			if (output.front() == '+') {
				sum = left + right;
			} else if (output.front() == '-') {
				sum = left - right;
			} else if (output.front() == '*') {
				sum = left * right;
			} else {
				sum = left / right;
			}
			char newnumber[16];
			sprintf(newnumber, "%d", sum);
			//cout << sum << endl;
			result.push(sum);

		} else { // it's a number
			result.push(output.front());
		}
		output.pop();
	}
	return 1;
}

int main() {

	char input[] = "6 * 2 + 4 * 9";
	shuntingyard2RPN(input);
	return 0;
}

