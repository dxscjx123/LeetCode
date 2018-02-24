// 分析：
// 二分查找法。采用非递归方式，需要注意：1）left初始化为0，right
// 应该初始化为size-1，因为这样才能保证middle取到的是中间或者
// 中间的前一位。比如数组{1,3}，left=0，right=1，middle=(start+right)/2=0
// 如果right=size，则middle=1，取到数组元素3进行判断，不满足二分法
// 查找中间元素的性质。2）由于right=size-1，所以在进行二分查找是，边界条件
// 应该为left<=right，而不是left<right，因为right代表最右元素的下标。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int result = 0;
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        bool isfound = false;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle - 1;
            else if (nums[middle] < target)
                left = middle + 1;
            else
            {
                result = middle;
                isfound = true;
                break;
            }
        }
        if (!isfound)
            result = left;
        return result;
    }
};