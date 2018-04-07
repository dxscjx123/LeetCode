// 分析：状态转移方程如下
// f(0) = nums[0]
// f(1) = nums[1]
// f(2) = nums[2] + f(0)
// f(3) = nums[3] + max(f(0),f(1))
// f(4) = nums[4] + max(f(1),f(2))
// ......
// f(x) = nums[x] + max(f(x-2),f(x-1))

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
			return 0;
		else if (nums.size() == 1)
			return nums[0];
		else if (nums.size() == 2)
			return max(nums[0], nums[1]);
		int f0 = nums[0];
		int f1 = nums[1];
		int f2 = nums[2] + f0;
		for (int i = 3; i < nums.size(); ++i)
		{
			int f = nums[i] + max(f0, f1);
			f0 = f1;
			f1 = f2;
			f2 = f;
		}
		return max(f1, f2);
    }
};