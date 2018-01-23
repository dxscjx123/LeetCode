// 分析：
// 逆波兰式，采用栈求解即可。

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are+,-,*,/. Each operand may be an integer or another expression.
// Some examples:
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty())
			return 0;
		for (auto token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				int behind = num.top();
				num.pop();
				int front = num.top();
				num.pop();
				int result;
				if (token == "+")
					result = front + behind;
				else if (token == "-")
					result = front - behind;
				else if (token == "*")
					result = front * behind;
				else if (token == "/")
					result = front / behind;
				num.push(result);
			}
			else 
			{
				num.push(stoi(token));
			}
		}
		return num.top();
    }
private:
	stack<int> num;
};