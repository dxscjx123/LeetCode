// 分析：
// 对vector进行排序，采用快排实现。对链表进行排序相应参照148题。

class Solution {
public:
	int Partition(vector<int> &nums, int start, int end)
	{
		int i = start;
		int j = end;
		int flag = nums[start];
		while (i < j)
		{
			while (i < j && nums[j] >= flag)
				j--;
			while (i < j && nums[i] <= flag)
				i++;
			if (i < j)
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
		nums[start] = nums[i];
		nums[i] = flag;
		return i;
	}

	void quicksort(vector<int> &nums, int start, int end)
	{
		if (start >= end)
			return ;
		int index = Partition(nums, start, end);
		quicksort(nums, start, index - 1);
		quicksort(nums, index + 1, end);
	}
	
    void sortColors(vector<int>& nums) {
		if (nums.empty())
			return ;
		quicksort(nums, 0, nums.size() - 1);
    }
};