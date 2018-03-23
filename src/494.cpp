// 分析：
// 采用回溯法。其实dfs部分代码写成
// if (counta <= nums.size() && index < nums.size())
// {
	// counta++;
	// cursum += nums[index];
	// dfs(nums, index + 1, counta, countb, cursum, S, str + "+");
	// cursum -= nums[index];
	// counta--;
// }
// if (countb <= nums.size() && index < nums.size())
// {
	// countb++;
	// cursum -= nums[index];
	// dfs(nums, index + 1, counta, countb, cursum, S, str + "-");
	// cursum += nums[index];
	// countb--;
// }
// 还更好理解回溯本质。
// 统计符号数量，两者之和如果等于nums的长度，则判断当前加和是否等于目的值。在每次dfs返回后，
// 当前结果不满足条件或者已经满足条件，故将当前结果加入或减去（见上述注释代码）

class Solution {
public:
	void dfs(vector<int> &nums, int index, int counta, int countb, int cursum, int S)
	{
		if (counta + countb == nums.size())
		{
		    if (cursum == S)
                result++;
			return ;
		}
		if (counta <= nums.size() && index < nums.size())
			dfs(nums, index + 1, counta + 1, countb, cursum + nums[index], S);
		if (countb <= nums.size() && index < nums.size())
			dfs(nums, index + 1, counta, countb + 1, cursum - nums[index], S);
	}

    int findTargetSumWays(vector<int>& nums, int S) {
		result = 0;
		str = string();
		dfs(nums, 0, 0, 0, 0, S);
		return result;
	}
private:
	int result;
	string str;
};
