// 分析：
// 判断两个树是否相同，递归遍历相同位置的节点，如果两者有一个节点不存在或者节点存在但
// 值不同，则两棵树不同。

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
	void issametree(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return ;
		if ((!p && q) || (p && !q))
		{
			result = false;
			return ;
		}
		if (p->val != q->val)
			result = false;
		issametree(p->left, q->left);
		issametree(p->right, q->right);
	}

    bool isSameTree(TreeNode* p, TreeNode* q) {
		result = true;
		issametree(p, q);
		return result;
    }
private:
	bool result;
};