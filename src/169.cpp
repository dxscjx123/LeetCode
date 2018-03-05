// 分析：
// 找出数组中出现次数超过一半的数。可以采用的方法有：
// （1）采用哈希表，统计每个数出现的次数，超过一半则输出；
// （2）对数组进行排序，排序后的数组中位数即为超过一半的数。排序算法可以采用快排。
// （3）对数组进行递归处理。分别对数组左右进行递归，如果递归只有一个元素，返回当前
// 元素。如果递归后左边元素等于右边元素，则返回任意（左边元素）。如果左边不等于右边
// 则对左右进行遍历计算次数，返回次数多的元素。

//采用哈希表：
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mapping;
		int result;
		for (int i = 0; i < nums.size(); ++i)
		{
			int ele = nums[i];
			if (mapping.find(ele) == nums.end())
				mapping[ele] = 1;
			else
				++mapping[ele];
			if (mapping[ele] == nums.size() / 2 + 1)
			{
				result = ele;
				break;
			}
		}
		return result;
    }
};

//采用快排:
//一个大测试用例没有通过。
/*
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

    int majorityElement(vector<int>& nums) {
		quicksort(nums, 0, nums.size() - 1);
		int mid = nums.size() / 2;
		return nums[mid];
    }
};
*/

//采用递归分治：
/*
class Solution {
public:
	int countnumber(vector<int> &nums, int num, int start, int end)
	{
		int sum = 0;
		for (int i = start; i <= end; ++i)
		{
			if (nums[i] == num)
				sum += 1;
		}
		return sum;
	}

	int majorityelement(vector<int> &nums, int start, int end)
	{
		if (start == end)
			return nums[start];
		
		int mid = (start + end) / 2;
		int left = majorityelement(nums, start, mid);
		int right = majorityelement(nums, mid + 1, end);
		
		if (left == right)
			return left;
		
		int countleft = countnumber(nums, left, start, mid);
		int countright = countnumber(nums, right, mid + 1, end);
		
		return (countleft > countright) ? left : right;
	}
	
    int majorityElement(vector<int>& nums) {
		return majorityelement(nums, 0, nums.size() - 1);
    }
};
*/