// 分析：
//方法一：
// 二叉查找树的中序遍历结果是一个有序数组，对其进行中序遍历，并将结果存入result，
// 对result相邻元素计算差值，返回差值的最小值。
//由于需要result保存结果，故需要额外的空间复杂度。
// 方法二：
// 可以采用直接在中序遍历的过程中计算差值。prev保存前一个遍历节点，并每次遍历到中间
// 节点时更新到当前节点值。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//方法一：
class Solution {
public:
	void inorder(TreeNode *root)
	{
		if (!root)
			return ;
		inorder(root->left);
		result.push_back(root->val);
		inorder(root->right);
	}

    int minDiffInBST(TreeNode* root) {
		mindis = INT_MAX;
		inorder(root);
		for (int i = 0; i < result.size() - 1; ++i)
		{
			int dis = result[i+1] - result[i];
			if (dis < mindis)
				mindis = dis;
		}
		return mindis;
    }
	
private:
	vector<int> result;
	int mindis;
};

//方法二：
/*
class Solution {
public:
	void inorder(TreeNode *root)
	{
		if (!root)
			return ;
		inorder(root->left);
		if (prev != -1)
			mindis = min(mindis, root->val - prev);
		prev = root->val;
		inorder(root->right);
	}

    int minDiffInBST(TreeNode* root) {
		mindis = INT_MAX;
		prev = -1;
		inorder(root);
		return mindis;
    }
	
private:
	int prev;
	int mindis;
};
*/