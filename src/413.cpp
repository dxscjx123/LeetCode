// 分析：
// 看个例子，1,2,3,4,5。对于1,2,3，累加个数为1，此时加入4(多了2,3,4;1,2,3,4两种情况)
// 则在上次结果的基础上累加个数1。状态方程为dp[i] = dp[i-1] + 1。

class Solution {
public:
	bool is_ok(vector<int> &A, int i)
	{
		bool ret = false;
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
			ret = true;
		return ret;
	}

    int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)
			return 0;
		vector<int> dp(A.size(), 0);
		int result = 0;
		for (int i = 2; i < A.size(); ++i)
		{
			if (is_ok(A, i))
				dp[i] = dp[i - 1] + 1;
			result += dp[i];
		}
		return result;
    }
};

//内存占用过大
/*
class Solution {
public:
	bool is_ok(vector<int> &A, int i, int j)
	{
		bool ret = false;
		if (A[j] - A[j - 1] == A[i + 1] - A[i])
			ret = true;
		return ret;
	}

    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
			return 0;
		vector<vector<int>> dp;
		dp.resize(A.size(), vector<int>(A.size(), 0));
		int result = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = i + 2; j < A.size(); ++j)
			{
				if (j - i == 2 || dp[i][j - 1])
				{
					if (is_ok(A, i, j))
					{
						dp[i][j] = 1;
						result++;
					}
				}
				else
					break;
			}
		}
		return result;
    }
};
*/