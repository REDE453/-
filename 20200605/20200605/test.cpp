#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	string expre;
	while (cin >> expre) {
		vector<char> exp;
		stack<char> op;
		// 3-10+(0+(10+5+3)-10)
		// 3 10 - 0 10 5 + 3 + + 10 - +
		for (size_t i = 0; i < expre.length(); i++) {
			if (expre[i] >= '0' && expre[i] <= '9') {
				if (i > 0 && expre[i - 1] >= '0' && expre[i - 1] <= '9') {
					int tmp = exp.back() - '0';
					tmp = tmp * 10 + expre[i];
					exp.pop_back();
					exp.push_back(tmp);
				}
				else {
					exp.push_back(expre[i]);
				}
			}
			else if (expre[i] == ')') {
				while (!op.empty() && op.top() != '(') {
					exp.push_back(op.top());
					op.pop();
				}
				op.pop();
			}
			else if (expre[i] == '-' || expre[i] == '+') {
				if (expre[i] == '-') {
					if (i == 0 || expre[i - 1] == '(') {
						exp.push_back('0');
					}
				}
				while (!op.empty() && (op.top() == '+' || op.top() == '-' || op.top() == '*' || op.top() == '/')) {
					exp.push_back(op.top());
					op.pop();
				}
				op.push(expre[i]);
			}
			else if (expre[i] == '*' || expre[i] == '/') {
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					exp.push_back(op.top());
					op.pop();
				}
				op.push(expre[i]);
			}
			else {
				op.push(expre[i]);
			}
		}

		while (!op.empty()) {
			exp.push_back(op.top());
			op.pop();
		}

		stack<int> res;
		for (size_t i = 0; i < exp.size(); i++) {
			if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
				int val1 = res.top();
				res.pop();
				int val2 = res.top();
				res.pop();
				int tmp;
				if (exp[i] == '+') {
					tmp = val2 + val1;
				}
				else if (exp[i] == '-') {
					tmp = val2 - val1;
				}
				else if (exp[i] == '*') {
					tmp = val2 * val1;
				}
				else if (exp[i] == '/') {
					tmp = val2 / val1;
				}
				res.push(tmp);
			}
			else {
				res.push(exp[i] - '0');
			}
		}
		cout << res.top() << endl;
	}

	return 0;
}