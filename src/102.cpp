// 分析：
// 二叉树的层次遍历，类比107题。由于是顺序输出层次遍历结构，不需要用stack结构。

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
			result.push_back(oneresult);
		}
	}

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
			return result;
		bfs_queue.push(root);
		bfs(root);
		return result;
    }
private:
	vector<vector<int>> result;
	queue<TreeNode *> bfs_queue;
};