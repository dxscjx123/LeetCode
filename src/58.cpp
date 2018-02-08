// 分析：
// 主要是把各种测试用例的情况搞清。

class Solution {
public:
    int lengthOfLastWord(string s) {
		if (s.empty())
			return 0;
		int tmp_result = 0;
		int result = 0;
		for (auto v : s)
		{
			if (v == ' ')
			{
				tmp_result = 0;
				continue;
			}
			tmp_result++;
			result = tmp_result;
		}
		return result;
    }
};