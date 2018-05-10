// 分析：
// 加入元素的顺序：
// null
// 1
// 1,2
// 1,2,3（这里回溯后，将3移除，2随之移除，并进入到下一次for循环，压入3，此时
// 元素为1,3）
// 1,3
// ......

class Solution {
public:
	void dfs(int location, vector<int> &nums, vector<int> &oneresult)
	{
		result.push_back(oneresult);
		for (int i = location; i < nums.size(); ++i)
		{
			oneresult.push_back(nums[i]);
			dfs(i + 1, nums, oneresult);
			oneresult.pop_back();
		}
	}
	
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
			return result;
		vector<int> oneresult;
		dfs(0, nums, oneresult);
		return result;
    }
private:
	vector<vector<int>> result;
};