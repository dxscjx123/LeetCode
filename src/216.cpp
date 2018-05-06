// 分析：
// 这里稍微麻烦的一点就是1,2,4和4,2,1这样算是一种结果，输出结果中不能包含重复结果，所以
// isok函数用于判断当前数是否大于oneresult中的最后一个数，以按照升序插入结果，避免了重复输出。

class Solution {
public:
	bool isok(int current, vector<int> &oneresult)
	{
		bool result = false;
		if (oneresult.empty() || oneresult[oneresult.size() - 1] < current)
			result = true;
		return result;
	}

	void dfs(int cur_dep, int cur_sum, int dep, int sum, vector<int> &oneresult)
	{
		if (cur_dep == dep)
		{
			if (cur_sum == sum)
				result.push_back(oneresult);
			return ;
		}
		for (int i = 1; i <=9; ++i)
		{
			if (!visit[i] && isok(i, oneresult))
			{
				visit[i] = 1;
				oneresult.push_back(i);
				dfs(cur_dep + 1, cur_sum + i, dep, sum, oneresult);
				oneresult.pop_back();
				visit[i] = 0;
			}
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
        visit.resize(10, 0);
		vector<int> oneresult;
		dfs(0, 0, k, n, oneresult);
		return result;
    }
private:
	vector<int> visit;
	vector<vector<int>> result;
};