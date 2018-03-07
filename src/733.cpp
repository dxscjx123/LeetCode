// 分析：
// 采用dfs和bfs方法都可以。
// 主要是需要考虑对边界条件的判断。

//dfs
// 遍历到当前节点，将当前节点填充并标记当前节点已访问，分别递归访问当前节点上下左右四个方向满足条件的节点。
//需要维护一个visit，用于标记当前位置的节点是否被访问。
// 满足条件即：
// 1）该处的坐标满足边界要求；
// 2）未被访问；
// 3）该处的颜色与初始节点相同。

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
// 遍历当前节点，设置当前节点为已访问并将当前节点入队。只要队不为空，队头出队，并判断队头上下左右四个方向上的节点是否满足访问。
// 要求，如果满足则将该处节点入队，并标记为已访问。
// 满足访问要求，即：
// 1）坐标位置没有越界；
// 2）未被访问；
// 3）该处颜色与原始节点颜色相同。
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