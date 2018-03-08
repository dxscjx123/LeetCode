// 分析：
// 对于回溯而言，在当前局面下有若干种选择，尝试一种选择。如果发现某种
// 选择不符合条件则返回，否则将结果加入解集。
// 递归题需要考虑三个条件：
// 1）选择；
// 2）限制；
// 3）终止条件

// 对于本题来说，回溯法匹配括号。
// 当前情况下的选择有两种：1）加入左括号；2）加入右括号
// 限制条件为：1）如果左括号小于给定数，则可以加入左括号；2）如果右括号
// 小于左括号数，则可以加入合法的右括号；
// 终止条件：当左右括号数均用完，等于给定数，则返回。

class Solution {
public:
	void dfs(int left, int right, int n, string line)
	{
		if (left == n && right == n)
		{
			result.push_back(line);
			return ;
		}
		if (left < n)
		{
			line.push_back("(");
			dfs(left + 1, right, n, line);
			line.pop_back();
		}
		if (right < left)
		{
			line.push_back(")");
			dfs(left, right + 1, n, line);
			line.pop_back();
		}
	}

    vector<string> generateParenthesis(int n) {
		if (n == 0)
			vector<string>();
		string line;
		dfs(0, 0, n, line);
    }
private:
	vector<string> result;
};