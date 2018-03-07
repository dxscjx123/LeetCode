// 分析：
// 采用dfs和bfs方法都可以。
// 主要是需要考虑对边界条件的判断。

//dfs
class Solution {
public:
	bool issame(vector<vector<int>> &image, int sr, int sc, int original)
	{
		bool result = true;
		if (image[sr][sc] != original)
			result = false;
		return result;
	}

	void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int original)
	{
		image[sr][sc] = newColor;
		visit[sr][sc] = 1;
		if (sr - 1 >= 0 && issame(image, sr - 1, sc, original) && !visit[sr - 1][sc])
			dfs(image, sr - 1, sc, newColor, original);
		if (sr + 1 <= image.size() - 1 && issame(image, sr + 1, sc, original) && !visit[sr + 1][sc])
			dfs(image, sr + 1, sc, newColor, original);
		if (sc - 1 >= 0 && issame(image, sr, sc - 1, original) && !visit[sr][sc - 1])
			dfs(image, sr, sc - 1, newColor, original);
		if (sc + 1 <= image[0].size() - 1 && issame(image, sr, sc + 1, original) && !visit[sr][sc + 1])
			dfs(image, sr, sc + 1, newColor, original);
	}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty())
			return image;
		
		visit.resize(image.size(), vector<int>(image[0].size(), 0));

		original = image[sr][sc];
		dfs(image, sr, sc, newColor, original);
		return image;
    }

private:
	vector<vector<int>> visit;
	int original;
};

//bfs
class Solution {
public:
	bool issame(vector<vector<int>> &image, int sr, int sc, int original)
	{
		bool result = true;
		if (image[sr][sc] != original)
			result = false;
		return result;
	}

	void bfs(vector<vector<int>> &image, int sr, int sc, int newColor)
	{
		image[sr][sc] = newColor;
		visit[sr][sc] = 1;
		while (!bfs_queue.empty())
		{
			vector<int> cur = bfs_queue.front();
			bfs_queue.pop();
			if (cur[0] - 1 >= 0 && issame(image, cur[0] - 1, cur[1], original) && !visit[cur[0] - 1][cur[1]])
			{
				vector<int> up = {cur[0] - 1, cur[1]};
				bfs_queue.push(up);
				image[cur[0] - 1][cur[1]] = newColor;
				visit[cur[0] - 1][cur[1]] = 1;
			}
			if (cur[0] + 1 <= image.size() - 1 && issame(image, cur[0] + 1, cur[1], original) && !visit[cur[0] + 1][cur[1]])
			{
				vector<int> down = {cur[0] + 1, cur[1]};
				bfs_queue.push(down);
				image[cur[0] + 1][cur[1]] = newColor;
				visit[cur[0] + 1][cur[1]] = 1;
			}
			if (cur[1] - 1 >= 0 && issame(image, cur[0], cur[1] - 1, original) && !visit[cur[0]][cur[1] - 1])
			{
				vector<int> left = {cur[0], cur[1] - 1};
				bfs_queue.push(left);
				image[cur[0]][cur[1] - 1] = newColor;
				visit[cur[0]][cur[1] - 1] = 1;
			}
			if (cur[1] + 1 <= image[0].size() - 1 && issame(image, cur[0], cur[1] + 1, original) && !visit[cur[0]][cur[1] + 1])
			{
				vector<int> right = {cur[0], cur[1] + 1};
				bfs_queue.push(right);
				image[cur[0]][cur[1] + 1] = newColor;
				visit[cur[0]][cur[1] + 1] = 1;
			}
		}
	}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty())
			return image;

		visit.resize(image.size(), vector<int>(image[0].size(), 0));

		original = image[sr][sc];
		vector<int> head = {sr, sc};
		bfs_queue.push(head);
		bfs(image, sr, sc, newColor);
		return image;
    }

private:
	queue<vector<int>> bfs_queue;
	vector<vector<int>> visit;
	int original;
};