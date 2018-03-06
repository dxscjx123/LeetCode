// 分析：
// 中序遍历，与783题类似。

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
	void inorder(TreeNode *root)
	{
		if (!root)
			return ;
		inorder(root->left);
		if (prev != -1)
			minnum = min(minnum, root->val-prev);
		prev = root->val;
		inorder(root->right);
	}

    int getMinimumDifference(TreeNode* root) {
        minnum = INT_MAX;
		prev = -1;
		inorder(root);
		return minnum;
    }
private:
	int minnum;
	int prev;
};