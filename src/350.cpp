// 分析：
// 相较于349题，不在限制只能存入非重复元素。则对每个查找到的元素，都存入到result。

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
		if (nums1.empty() || nums2.empty())
			return result;
		
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		
		auto iter1 = nums1.begin();
		auto iter2 = nums2.begin();
		
		while (iter1 < nums1.end() && iter2 < nums2.end())
		{
			bool isfound = false;
			int tmp;
			if (*iter1 < *iter2)
				iter1++;
			else if (*iter1 > *iter2)
				iter2++;
			else
			{
				tmp = *iter1;
				isfound = true;
				iter1++;
				iter2++;
			}
			
			if (isfound)
				result.push_back(tmp);
		}
		return result;
    }
};