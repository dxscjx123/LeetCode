// 分析：
// start用于记录当前位置，每次for循环从start开始遍历，保证了不会向前遍历
// 导致重复元素。

class Solution {
public:
	void dfs(int start, int end, int k, vector<int> oneresult)
	{
		if (oneresult.size() == k)
		{
			result.push_back(oneresult);
			return ;
		}
		for (int i = start; i <= end; ++i)
		{
			oneresult.push_back(i);
			dfs(i + 1, end, k, oneresult);
			oneresult.pop_back();
		}
	}

    vector<vector<int>> combine(int n, int k) {
		vector<int> oneresult;
		dfs(1, n, k, oneresult);
		return result;
    }
private:
	vector<vector<int>> result;
};