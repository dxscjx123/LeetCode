// 分析：
// 查找从一个节点到叶节点是否存在和等于给定值的路径。对二叉树进行
// dfs，累加每个节点的权值。由于题意是从根节点到叶节点，如果未到达
// 叶节点就满足条件了，不符合题意，故需要判断当前节点是否是叶节点。

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
	void dfs(TreeNode *root, int cursum, int sum)
	{
		cursum += root->val;
		if (root->left)
			dfs(root->left, cursum, sum);
		if (root->right)
			dfs(root->right, cursum, sum);
		if (!root->left && !root->right && cursum == sum)
			result = true;
	}

    bool hasPathSum(TreeNode* root, int sum) {
        result = false;
		if (!root)
			return result;
		int cursum = 0;
		dfs(root, cursum, sum);
		return result;
	}
private:
	bool result;
};