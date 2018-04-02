// 分析：
// 对树进行层次遍历，返回下一层的第一个元素即可。用队列结构的话，即队头。
// 每次对队头进行更新。

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
			int levelsum = bfs_queue.size();
			if (levelsum > 0)
				result = bfs_queue.front();
			for (int i = 0; i < levelsum; ++i)
			{
				TreeNode *head = bfs_queue.front();
				bfs_queue.pop();
				if (head->left)
					bfs_queue.push(head->left);
				if (head->right)
					bfs_queue.push(head->right);
			}
		}
	}

    int findBottomLeftValue(TreeNode* root) {
        if (!root)
			return 0;
		bfs_queue.push(root);
		result = nullptr;
		bfs(root);
		return result->val;
    }
	
private:
	queue<TreeNode *> bfs_queue;
	TreeNode *result;
};