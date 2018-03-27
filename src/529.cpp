// 分析：
// 这个题仔细分析一下是一个dfs的问题。但对于判定条件比较多需要考虑。直接
// 在代码中说明吧。

class Solution {
public:
	bool isM(vector<vector<char>> &board, vector<int> &click)
	{
		bool result = false;
		int row = click[0];
		int col = click[1];
		if (board[row][col] == 'M')
			result = true;
		return result;
	}
	
	bool isE(vector<vector<char>> &board, int row, int col, char current)
	{
		bool result = false;
		if (board[row][col] == 'E' && current == 'B')
			result = true;
		return result;
	}

	int dightcount(vector<vector<char>> &board, vector<int> &click)
	{
		int count = 0;
		int row = click[0];
		int col = click[1];
		if (row - 1 >= 0 && col - 1 >= 0)
			count += (board[row - 1][col - 1] == 'M') ? 1 : 0;
		if (row - 1 >= 0)
			count += (board[row - 1][col] == 'M') ? 1 : 0;
		if (row - 1 >= 0 && col + 1 < board[0].size())
			count += (board[row - 1][col + 1] == 'M') ? 1 : 0;
		if (col - 1 >= 0)
			count += (board[row][col - 1] == 'M') ? 1 : 0;
		if (col + 1 < board[0].size())
			count += (board[row][col + 1] == 'M') ? 1 : 0;
		if (row + 1 < board.size() && col - 1 >= 0)
			count += (board[row + 1][col - 1] == 'M') ? 1 : 0;
		if (row + 1 < board.size())
			count += (board[row + 1][col] == 'M') ? 1 : 0;
		if (row + 1 < board.size() && col + 1 < board[0].size())
			count += (board[row + 1][col + 1] == 'M') ? 1 : 0;
		return count;
	}
	
	void dfs(vector<vector<char>> &board, vector<int> &click)
	{
		int row = click[0];
		int col = click[1];
		visit[row][col] = 1;   //设置当前已访问
		if (isM(board, click))   //是不是雷，是则设置X
		{
			board[row][col] = 'X';
			return ;
		}
		
		int count = dightcount(board, click);   //不是雷，统计周围有多少个雷
		if (count)
		{
			char c;
			sprintf(&c, "%d", count);
			board[row][col] = c;  //设置雷数量
		}
		else
			board[row][col] = 'B';   //周围没有雷，设置为'B'
		
		if (row - 1 >= 0 && isE(board, row - 1, col, board[row][col]) && !visit[row - 1][col])  //下一个是不是E，并且没有被访问，并且当前是'B'
		{
			vector<int> up = {row - 1, col};
			dfs(board, up);
		}
		if (row + 1 < board.size() && isE(board, row + 1, col, board[row][col]) && !visit[row + 1][col])
		{
			vector<int> down = {row + 1, col};
			dfs(board, down);
		}
		if (col - 1 >= 0 && isE(board, row, col - 1, board[row][col]) && !visit[row][col - 1])
		{
			vector<int> left = {row, col - 1};
			dfs(board, left);
		}
		if (col + 1 < board[0].size() && isE(board, row, col + 1, board[row][col]) && !visit[row][col + 1])
		{
			vector<int> right = {row, col + 1};
			dfs(board, right);
		}
	}

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (board.empty())
			return vector<vector<char>>();
		visit.resize(board.size(), vector<int>(board[0].size(), 0));
		dfs(board, click);
		return board;
    }
private:
	vector<vector<int>> visit;
};