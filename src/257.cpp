// 分析：
// 打印二叉树的路径，对每个节点进行dfs查找，不是叶节点，添加到path中，到达叶节点
// 将path加入到result中。
// 最初的失误：
	// void dfs(TreeNode *root, string path, vector<string> &result)
	// {
		// path += to_string(root->val);
		// if (root->left)
			// dfs(root->left, path + "->", result);
		// if (root->right)
			// dfs(root->right, path + "->", result);
		// result.push_back(path);
	// }
// 想法是既没有左子树也没有右子树，即到达叶子节点，走到最后一行，将结果加入。但对于
// 上述代码，两个if分支返回后同样也会走到最后一行代码。故依然需要添加判断if(!root->left && !root->right)

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
	void dfs(TreeNode *root, string path, vector<string> &result)
	{
		path += to_string(root->val);
		if (!root->left && !root->right)
		{
			result.push_back(path);
			return ;
		}
		if (root->left)
			dfs(root->left, path + "->", result);
		if (root->right)
			dfs(root->right, path + "->", result);
	}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
		if (!root)
			return result;
		string path;
		dfs(root, path, result);
		return result;
    }
};