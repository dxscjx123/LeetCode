// 分析：
// 判断两个单词是否是重构词，即是否单词类型和次数相同，但组合不同。
// 方法一：对两个单词进行排序，判断排序后两个单词是否相同，速度较慢；
// 方法二：构建一个哈希表，在s中出现的字符存入哈希表，value++，在t中
// 出现的字符，value--。最终判断哈希表中迭代器，iter->second是否都为
// 0。

class Solution {
public:
    bool isAnagram(string s, string t) {
        bool result = false;
		if (s.size() != t.size())
			return result;
		
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		
		if (s == t)
			result = true;
		return result;
    }
};