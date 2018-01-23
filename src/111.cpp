class Solution {
public:
    int run(TreeNode *root) {
		if (!root)
			return 0;
		if (root->left == nullptr)
			return run(root->right) + 1;
		if (root->right == nullptr)
			return run(root->left) + 1;
		return min(run(root->left), run(root->right)) + 1;
	}
};