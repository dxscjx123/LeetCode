// 分析：
// 可以重复遍历当前位置，但只能往后走，不能向前，避免重复。故每次将当前位置传入，并从当前位置开始遍历。
// 注释为第一次的代码，效率很低，就是每次遍历都从头开始，为了去除重复，引入set，将每次结果排序后匹配set，
// 并存入结果result。

class Solution {
public:
	void dfs(int location, vector<int> &oneresult, int &cur_sum, vector<int> &candidates, int &target)
	{
		if (cur_sum == target)
			result.push_back(oneresult);
		else if (cur_sum < target)
		{
			for (int i = location; i < candidates.size(); ++i)
			{
				oneresult.push_back(candidates[i]);
				cur_sum += candidates[i];
				dfs(i, oneresult, cur_sum, candidates, target);
				cur_sum -= candidates[i];
				oneresult.pop_back();
			}
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty())
			return result;
		vector<int> oneresult;
		int cur_sum = 0;
		dfs(0, oneresult, cur_sum, candidates, target);
		return result;
    }
private:
	vector<vector<int>> result;
	set<vector<int>> setting;
};

/*
class Solution {
public:
	void dfs(vector<int> &oneresult, int cur_sum, vector<int> &candidates, int &target)
	{
		for (int i = 0; i < candidates.size(); ++i)
		{
			if (cur_sum < target)
			{
				oneresult.push_back(candidates[i]);
				cur_sum += candidates[i];
				dfs(oneresult, cur_sum, candidates, target);
				cur_sum -= candidates[i];
				oneresult.pop_back();
			}
			else if (cur_sum == target)
			{
				vector<int> tmp = oneresult;
				sort(tmp.begin(), tmp.end());
				if (setting.find(tmp) == setting.end())
				{
					setting.insert(tmp);
					result.push_back(tmp);
				}
				break;
			}
			else
				break;
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty())
			return result;
		vector<int> oneresult;
		int cur_sum = 0;
		dfs(oneresult, cur_sum, candidates, target);
		return result;
    }
private:
	vector<vector<int>> result;
	set<vector<int>> setting;
};
*/