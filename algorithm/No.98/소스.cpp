#include <vector>
#include <map>
using namespace std;
int int_board[101][101] = { 0, };
int bool_board[101][101] = { false, };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

map<int, int> m;
void dfs(int col, int row, int m, int n) {
	for (int i = 0; i < 4; i++)
	{
		int my = col + dy[i];
		int mx = row + dx[i];
		if ((0 <= mx && mx < n) && (0 <= my && my < m) && int_board[col][row] == int_board[my][mx]) {
			if (m[int_board[col][row]]);
		}
	}
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int col = 0; col < m; col++)
	{
		for (int row = 0; row < n; row++)
		{
			int_board[col][row] = picture[col][row];
			if (picture[col][row] != 0)bool_board[col][row] = true;
		}
	}

	for (int col = 0; col < m; col++)
	{
		for (int row = 0; row < n; row++)
		{
			if (int_board[col][row] == 0)continue;
			dfs(col, row, m, n);
		}
	}


	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}