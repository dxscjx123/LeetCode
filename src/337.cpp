// 分析：
// 对于当前节点的权值计算有两种：第一种是当前节点的权值加上其孙子节点的权值，
// 另一种是当前节点左右子节点的权值和，上述两种情况取得最大值。采用哈希表保存
// 已经遍历过的节点权值，便于后续进行查找直接返回。

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
	int dfs(TreeNode *root)
	{
		if (!root)
			return 0;
		if (mapping.find(root) != mapping.end())
			return mapping[root];
		int cur_val = 0;
		if (root->left)
			cur_val += dfs(root->left->left) + dfs(root->left->right);
		if (root->right)
			cur_val += dfs(root->right->left) + dfs(root->right->right);
		cur_val = max(root->val + cur_val, dfs(root->left) + dfs(root->right));
		mapping[root] = cur_val;
		return cur_val;
	}

    int rob(TreeNode* root) {
		if (!root)
			return 0;
		int result = dfs(root);
		return result;
    }
private:
	unordered_map<TreeNode *, int> mapping;
};