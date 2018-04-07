// 分析：状态方程如下
// f(0) = cost(0)
// f(1) = cost(1)
// f(2) = cost(2) + min[f(0),f(1)]
// ......
// f(x) = cost(x) + min[f(x-2),f(x-1)]
// 由于一次只能上1或2级台阶，则倒数第二次的情况，位于最后一级或倒数第二级台阶。
// 而当前的总的最优cost值，就等于当前值加上前面两次的最优值。

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int f0 = cost[0];
		int f1 = cost[1];
		for (int i = 2; i < cost.size(); ++i)
		{
			int f = cost[i] + min(f0, f1);
			f0 = f1;
			f1 = f;
		}
		return min(f0, f1);
    }
};