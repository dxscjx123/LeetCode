// 分析：
// 起始位置从0开始算，dfs的终止条件为等于nums.size()的时候。

class Solution {
public:
	void dfs(int cur_location, vector<int> &nums, vector<int> &oneresult)
	{
		if (cur_location == nums.size())
		{
			result.push_back(oneresult);
			return ;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (!visit[i])
			{
				visit[i] = 1;
				oneresult.push_back(nums[i]);
				dfs(cur_location + 1, nums, oneresult);
				oneresult.pop_back();
				visit[i] = 0;
			}
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
        visit.resize(nums.size(), 0);
		vector<int> oneresult;
		dfs(0, nums, oneresult);
		return result;
    }
private:
	vector<int> visit;
	vector<vector<int>> result;
};