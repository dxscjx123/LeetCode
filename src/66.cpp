// 分析：
// 把加1理解为进位1，直接对末尾进行进位。

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
		for(auto iter = digits.rbegin(); iter != digits.rend(); ++iter)
		{
			int sum = *iter + carry;
			carry = sum / 10;
			sum = sum % 10;
			*iter = sum;
		}
		if (carry > 0)
			digits.insert(digits.begin(), carry);
		return digits;
    }
};