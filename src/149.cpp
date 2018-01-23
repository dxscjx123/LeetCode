// 分析：
// 本方法采用的最为传统的方法，即对所有点，两两结合计算直线方程，并判断第三个点是否在该直线方程上。这里需要考虑的一点是，对于两个点横坐标相等时，不存在斜率。
// 本题在计算直线时没有进行除法计算斜率，因为除法可能产生double类型无限
// 不循环小数。
// 具体：
// 定义直线方程：y = kx + b
// 通过两个点，则有：y1 = kx1 + b，y2 = kx2 + b，k = (y2 - y1)/(x2 - x1)
// b = y1 - kx1
// 带入第三个点(x3,y3)，则三点共线应该满足：
// y3(x2-x1) = (y2-y1)x3 + (x2-x1)b，带入b即可。

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if (points.size() < 3)
			return points.size();
		int result = 0;
		for (int i = 0; i < points.size(); ++i)
		{
			for (int j = i + 1; j < points.size(); ++j)
			{
				int x1 = points[i].x;
				int y1 = points[i].y;

				int x2 = points[j].x;
				int y2 = points[j].y;

				bool slope = true;
				if (x1 == x2)
					slope = false;

				int count = 0;
				for (int k = 0; k < points.size(); ++k)
				{
					int x3 = points[k].x;
					int y3 = points[k].y;

					if ((!slope && x3 == x2) || (slope && (y3 * (x2 - x1) == (x3 * (y2 - y1) + y1 * (x2 - x1) - x1 * (y2 - y1)))))
						++count;
				}
				if (count > result)
					result = count;
			}
		}
		return result;
    }
};