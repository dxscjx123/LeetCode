// 分析：
// 二分法查找。

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left = 1;
		long right = n;
		long result_num = 0;
		while (left <= right)
		{
			long mid = (left + right) / 2;
			long result = guess(mid);
			if (result == -1)
				right = mid - 1;
			else if (result == 1)
				left = mid + 1;
			else
			{
				result_num = mid;
				break;
			}
		}
		return (int)result_num;
    }
};