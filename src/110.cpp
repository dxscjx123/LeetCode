// 分析：
// 判断一棵二叉树是否是平衡的，即左右子树是否存在差值大于1的情况。
// 对于空树，其定义为平衡树。
// 递归遍历二叉树，计算其左右子树深度，叶节点返回深度为0，递归函数
// 返回当前节点的深度，所以函数返回左右子树的较大值。

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
	int subtreedepth(TreeNode *root)
	{
		if (!root)
			return 0;
		int left = subtreedepth(root->left) + 1;
		int right = subtreedepth(root->right) + 1;
		if (abs(left - right) > 1)
			result = false;
		return (left > right) ? left : right;
	}

    bool isBalanced(TreeNode* root) {
        result = true;
		if (!root)
			return true;
		subtreedepth(root);
		return result;
    }
private:
	bool result;
};