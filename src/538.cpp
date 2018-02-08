// 分析：
// 由于是一棵二叉查找树，最右结点是最大的，直接对树进行右中左遍历，并累加结点权值
// 就可以更新整个二叉树。

// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
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
	void convertbst(TreeNode *root)
	{
		if (!root)
			return;
		convertbst(root->right);
		sum += root->val;
		root->val = sum;
		convertbst(root->left);
	}
	
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
			return nullptr;
		sum = 0;
		convertbst(root);
		return root;
    }
private:
	int sum;
};