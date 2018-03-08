// 分析：
// 对树进行层次遍历（bfs）。由于采用queue结构不能够有效区分出哪些
// 节点属于哪一层，故统计每次队列中的个数size，将size个结点出队并
// 存入stack结构。最后将stack存入到result中

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void bfs(TreeNode *root)
	{
		while (!bfs_queue.empty())
		{
			vector<int> oneresult;
			int bfs_qsize = bfs_queue.size();
			for (int i = 0; i < bfs_qsize; ++i)
			{
				TreeNode *cur = bfs_queue.front();
				bfs_queue.pop();
				oneresult.push_back(cur->val);
				if (cur->left)
					bfs_queue.push(cur->left);
				if (cur->right)
					bfs_queue.push(cur->right);
			}
			cout<<"bfs_size"<<bfs_qsize<<endl;
			bottom_up.push(oneresult);
		}
	}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
			return result;
		bfs_queue.push(root);
		bfs(root);
		while (!bottom_up.empty())
		{
			vector<int> tmp = bottom_up.top();
			bottom_up.pop();
			result.push_back(tmp);
		}
		return result;
    }
private:
	vector<vector<int>> result;
	queue<TreeNode *> bfs_queue;
	stack<vector<int>> bottom_up;
};