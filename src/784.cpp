// 分析：
// 如果当前位置是大写或小写，则进行转换，并设置对应的大小写标志位，用于在回溯时将其
// 重新转换为大写或小写，回溯后重新递归生成新的结果。

class Solution {
public:
	void dfs(int start, int end, string s)
	{
		if (start == end)
		{
			result.push_back(s);
			return ;
		}

		bool istrans_low = false;
		bool istrans_up = false;
		if (s[start] >= 'a' && s[start] <= 'z')
		{
			s[start] -= 32;
			istrans_low = true;
		}
		else if (s[start] >= 'A' && s[start] <= 'Z')
        {
            s[start] += 32;
            istrans_up = true;
        }

		dfs(start + 1, end, s);

		if (istrans_low)
		{
			s[start] += 32;
			dfs(start + 1, end, s);
		}
		else if (istrans_up)
        {
            s[start] -= 32;
            dfs(start + 1, end, s);
        }
	}

    vector<string> letterCasePermutation(string S) {
        if (S.empty())
            return vector<string>(1, "");
		dfs(0, S.size(), S);
		return result;
    }
private:
	vector<string> result;
};