// 分析：
// 层次遍历，对每一层遍历的数替换最大值。

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
		while (bfs_queue.size())
		{
			int tmp = INT_MIN;
			int levelsum = bfs_queue.size();
			for (int i = 0; i < levelsum; ++i)
			{
				TreeNode *head = bfs_queue.front();
				bfs_queue.pop();
				if (head->val > tmp)
					tmp = head->val;
				if (head->left)
					bfs_queue.push(head->left);
				if (head->right)
					bfs_queue.push(head->right);
			}
			result.push_back(tmp);
		}
	}

    vector<int> largestValues(TreeNode* root) {
        if (!root)
			return vector<int>();
		bfs_queue.push(root);
		bfs(root);
		return result;
    }
private:
	queue<TreeNode *> bfs_queue;
	vector<int> result;
};