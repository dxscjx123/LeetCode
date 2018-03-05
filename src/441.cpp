// 分析：
// 采用二分法，每次采用等差数列求和，当小于给定数n，则表明当前mid过小，将left移动至
// mid+1，计算(left,mid+1)，否则计算(mid+1,right)，直到找到left>=right。

class Solution {
public:
    int arrangeCoins(int n) {
		if (n <= 1)
			return n;
		long left = 1;
		long right = n;
		while (left <= right)
		{
			long mid = (left + right) / 2;
			long sum = (1 + mid) * mid / 2;
			if (sum <= n)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return (int)(left - 1);
    }
};