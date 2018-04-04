// 分析：
// dfs方法
// 首先想到的思路是采用深搜。对没有被访问的元素循环遍历每一行，并依次遍历行中的伙伴元素，将被遍历元素标记为已遍历
// 递归遍历伙伴元素所在行。循环一次结束后，得到了从该行开始的遍历的所有伙伴元素，并对伙伴次数加1。

// 从题解报告学到了一种新的算法——并查集。
// 可以用于求解一个图中的所有连通子图。对于本题来说，主要思路为：首先初始化各个元素，标记所有元素为独立的连通分量（
// 设置父节点为元素下标），然后对每个元素的伙伴进行合并，合并方法为：先求两个合并元素是否有共同父节点，如果有则表明
// 已经是一个共有集合，直接返回，如果没有共同父节点，则设置其中一个合并元素的父节点指向另一个元素的父节点，此时两个
// 元素在同一个共有集合中。结合实现代码进行分析。

//dfs
class Solution {
public:
	void dfs(vector<vector<int>> &M, int row, int col)
	{
		visit[row] = 1;
		for (int i = 0; i < col; ++i)
		{
			if (!visit[i] && M[row][i] == 1)
				dfs(M, i, col);
		}
	}

    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty())
			return 0;
		
		visit.resize(M.size(), 0);
		result = 0;
		
		for (int row = 0; row < M.size(); ++row)
		{
			if (!visit[row])
			{
				dfs(M, row, M[0].size());
				result++;
			}
		}
		return result;
    }
private:
	vector<int> visit;
	int result;
};

//并查集
class Solution {
public:
	int find(int root)
	{
		if (root == parent[root])   //当前节点是父节点
			return root;
		int p_root = parent[root];
		return find(p_root);   //递归查找当前节点父节点
	}

	void __union(int x, int y)
	{
		int parent_x = find(x);   //返回x的父节点
		int parent_y = find(y);   //返回y的父节点
		if (parent_x == parent_y)   //具有公共父节点
			return ;
		parent[parent_y] = parent_x;   //设置y的父节点为x的父节点
		result--;   //合并后，连通分量数减去1
	}

    int findCircleNum(vector<vector<int>>& M) {
		if (M.empty())
			return 0;
		parent.resize(M.size(), 0);
		for (int i = 0; i < parent.size(); ++i)   //设置每个元素初始化连通分量值为其下标
			parent[i] = i;
		result = M.size();   //初始连通分量总量
		for (int i = 0; i < M.size() - 1; ++i)
		{
			for(int j = i + 1; j < M.size(); ++j)
			{
				if (M[i][j])   //对元素i，j进行合并
					__union(i, j);
			}
		}
		return result;
    }
private:
	vector<int> parent;
	int result;
};