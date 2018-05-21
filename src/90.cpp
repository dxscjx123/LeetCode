// 分析：
// 用一个set来记录重复。这里需要考虑乱序的情况，故首先先对nums进行排序。

class Solution {
public:
	void dfs(int start, int end, vector<int> oneresult, vector<int> &nums)
	{
		if (setting.find(oneresult) == setting.end())
		{
			result.push_back(oneresult);
			setting.insert(oneresult);
		}
		for (int i = start; i < end; ++i)
		{
			oneresult.push_back(nums[i]);
			dfs(i + 1, end, oneresult, nums);
			oneresult.pop_back();
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty())
			return result;
		vector<int> oneresult;
		sort(nums.begin(), nums.end());
		dfs(0, nums.size(), oneresult, nums);
		return result;
    }
private:
	vector<vector<int>> result;
	set<vector<int>> setting;
};