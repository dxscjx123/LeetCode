// 分析：
// 对每一个节点求和importance，采用bfs，将其subordinates放入队列中。
// 这里通过id号查找一个Employee采用循环遍历的方式，匹配id号。可以事先
// 定义哈希表，保存每个id与Employee映射，通过id可以快速索引Employee。

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
	void bfs(vector<Employee*> employees, queue<int> &bfs_queue, int &sum)
	{
		while (!bfs_queue.empty())
		{
			int id = bfs_queue.front();
			bfs_queue.pop();
			for (auto iter = employees.begin(); iter != employees.end(); ++iter)
			{
				if ((*iter)->id == id)
				{
					sum += (*iter)->importance;
					for (int i = 0; i < ((*iter)->subordinates).size(); ++i)
					{
						bfs_queue.push(((*iter)->subordinates)[i]);
					}
				}
			}
		}
	}

    int getImportance(vector<Employee*> employees, int id) {
        if (employees.empty())
			return 0;
		sum = 0;
		for (auto iter = employees.begin(); iter != employees.end(); ++iter)
		{
			if ((*iter)->id == id)
			{
				bfs_queue.push(id);
				break;
			}
		}
		bfs(employees, bfs_queue, sum);
		return sum;
		
    }
private:
	int sum;
	queue<int> bfs_queue;
};