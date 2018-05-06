// 分析：
// 常规的回溯。主要是dfs的终止条件，cur_location等于N时，还需要判断当前位置的元素是否满足条件，所以
// 终止条件应该为cur_location等于N+1

class Solution {
public:
	bool isok(int num, int location)
	{
		bool result = false;
		if (num % location == 0 || location % num == 0)
			result = true;
		return result;
	}
	
	void dfs(int cur_location, int N)
	{
		if (cur_location == N + 1)
		{
			result ++;
			return ;
		}
		for (int i = 1; i <= N; ++i)
		{
			if (!visit[i] && isok(i, cur_location))
			{
				visit[i] = 1;
				dfs(cur_location + 1, N);
				visit[i] = 0;
			}
		}
	}

    int countArrangement(int N) {
        visit.resize(N + 1, 0);
		int deep = N;
		result = 0;
		dfs(1, N);
		return result;
    }
private:
	vector<int> visit;
	int result;
};