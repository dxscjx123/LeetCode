// 分析：
// 这个题怎么感觉像找规律的题，不太清楚为什么会放在dp这一块。
// 先看前四个：第一列为元素（二进制），第二列为1的个数
// 0（00）		0
// 1（01）		1
// 2（10）		1
// 3（11）		2
// 4（0100）	f(1)+f(0)=1
// 5（0101）	f(1)+f(1)=2
// 6（0110）	f(1)+f(2)=2
// 7（0111）	f(1)+f(3)=3
// 8（1000）	f(2)+f(0)=1
// ......
// i			f(i/4)+f(i%4)
// 其实上述规律多写就看出来了，写到i=17时会比较明显。

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
			return vector<int>{0};
		if (num == 1)
			return vector<int>{0, 1};
		if (num == 2)
			return vector<int>{0, 1, 1};
		if (num == 3)
			return vector<int>{0, 1, 1, 2};
		
		vector<int> result = {0, 1, 1, 2};
		for (int i = 4; i < num + 1; ++ i)
		{
			int f = result[i / 4] + result[i % 4];
			result.push_back(f);
		}
		return result;
    }
};