链接：https://www.nowcoder.com/questionTerminal/22f9d7dd89374b6c8289e44237c70447?f=discussion
来源：牛客网

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> numbers;
		for (auto token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				int a, b, res;
				b = numbers.top(); numbers.pop();
				a = numbers.top(); numbers.pop();
				if (token == "+")
					res = a + b;
				else if (token == "-")
					res = a - b;
				else if (token == "*")
					res = a * b;
				else
					res = a / b;
				numbers.push(res);
			}
			else
			{
				stringstream ss;
				ss << token;
				int temp;
				ss >> temp;
				numbers.push(temp);
			}
		}
		return numbers.top();
	}
};