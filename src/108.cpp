// 分析：
// 需要把一个排序数组重新构建为一棵平衡二叉查找树。其实只需要按照
// 每次选择根节点是从数组的中点开始选择，构建的树即为平衡的。而每次
// 选择中间的数构建二叉树，是一个递归的过程。

// 在选择中间节点的过程中，mid=(start+end)/2，可能导致整数越界，求
// 中间数可以采用mid=start+(end-start)/2的方式。

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
	TreeNode *csttree(vector<int> &nums, int start, int end)
	{
		if (start > end)
			return nullptr;
		int mid = (start + end) / 2;
		//int mid = start + (end - start) / 2;
		int value = nums[mid];
		TreeNode *head = new TreeNode(value);
		head->left = csttree(nums, start, mid - 1);
		head->right = csttree(nums, mid + 1, end);
		return head;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
			return nullptr;
		TreeNode *head = csttree(nums, 0, nums.size() - 1);
		return head;
    }
};