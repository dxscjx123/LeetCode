// 分析：
// 二分查找。比较中间字符和target的大小，小于则在左边范围内查找，大于则在右边范围
// 内查找。循环退出时，left即为比target大的下一个字符下标。如果left=letters的长度，
// 则返回letters头元素。

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
		int right = letters.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			char s = letters[mid];
			if (s <= target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		char result;
		if (left == letters.size())
			result = letters[0];
		else
			result = letters[left];
		return result;
    }
};