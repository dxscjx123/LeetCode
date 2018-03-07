// 分析：
// 求一个最大的连通岛。对每个岛（不为0的节点）进行dfs递归遍历，记录连接该节点的岛，保存面积和，并更新
// 全局最大面积和result。对每个节点需要一个visit来保存节点是否被访问。在每次对一个节点的dfs递归完成后
// 需要对visit重置。

class Solution {
public:
	bool isok(vector<vector<int>> &grid, int sr, int sc)
	{
		bool result = false;
		if (grid[sr][sc] == 1)
			result = true;
		return result;
	}

	void dfs(vector<vector<int>> &grid, int sr, int sc, int &sum)
	{
		sum++;
		visit[sr][sc] = 1;
		if (sum > result)
			result = sum;
		if (sr - 1 >= 0 && isok(grid, sr - 1, sc) && !visit[sr - 1][sc])
			dfs(grid, sr - 1, sc, sum);
		if (sr + 1 <= grid.size() - 1 && isok(grid, sr + 1, sc) && !visit[sr + 1][sc])
			dfs(grid, sr + 1, sc, sum);
		if (sc - 1 >= 0 && isok(grid, sr, sc - 1) && !visit[sr][sc - 1])
			dfs(grid, sr, sc - 1, sum);
		if (sc + 1 <= grid[0].size() - 1 && isok(grid, sr, sc + 1) && !visit[sr][sc + 1])
			dfs(grid, sr, sc + 1, sum);
	}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
		result = INT_MIN;
		bool isfound = false;
        int sr = grid.size();
		int sc = grid[0].size();
		visit.resize(sr, vector<int>(sc, 0));
		for(int i = 0; i < sr; ++i)
			for (int j = 0; j < sc; ++j)
			{
				if (grid[i][j] != 0)
				{
					int sum = 0;
					dfs(grid, i, j, sum);
					isfound = true;
					visit.resize(sr, vector<int>(sc, 0));
					sum = 0;
				}
			}
		if (!isfound)
			result = 0;
		return result;
    }
private:
	int result;
	vector<vector<int>> visit;
};