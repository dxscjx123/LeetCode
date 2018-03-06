// 分析：
// 分别对nums1和nums2进行排序，然后从两个vector的首元素开始，iter1<iter2则iter1++，iter1>iter2则
// iter2++，相等则将当前找到的值存入result。result需要判断当前找到的值是否存在，重复则不再加入。
// 利用STL的sort函数结果是7ms，自行快排函数为10ms。

// 更为简洁的答案还有，采用set将num1存入，set具有元素唯一性。对nums2的每个元素，查找是否在set中，
// 若存在将结果加入到result，并将set中该元素删除（避免了后续的重复查找）。

class Solution {
public:
	void swap(int &num1, int &num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	int Partition(vector<int> &nums, int start, int end)
	{
		int i = start, j = end;
		int flag = nums[start];
		while (i < j)
		{
			while (i < j && nums[j] >= flag)
				j--;
			while (i < j && nums[i] <= flag)
				i++;
			if (i < j)
				swap(nums[i], nums[j]);
		}
		swap(nums[i], nums[start]);
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

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
		if (nums1.empty() || nums2.empty())
			return result;
		
		quicksort(nums1, 0, nums1.size() - 1);
		quicksort(nums2, 0, nums2.size() - 1);
		
		//sort(nums1.begin(), nums1.end());
		//sort(nums2.begin(), nums2.end());
		
		vector<int>::iterator iter1 = nums1.begin();
		vector<int>::iterator iter2 = nums2.begin();
		
		while (iter1 != nums1.end() && iter2 != nums2.end())
		{
			int tmp;
			bool isfound = false;
			if (*iter1 < *iter2)
			{
				iter1++;
			}
			else if (*iter1 > *iter2)
			{
				iter2++;
			}
			else
			{
				tmp = *iter1;
				isfound = true;
				iter1++;
				iter2++;
			}
			
			if (isfound)
			{
				if (result.empty())
					result.push_back(tmp);
				else if (result[result.size()-1] != tmp)
					result.push_back(tmp);
			}
		}
		return result;
    }
};