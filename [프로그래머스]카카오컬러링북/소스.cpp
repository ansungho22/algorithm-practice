#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
int int_board[101][101] = { 0, };
bool bool_board[101][101] = { false, };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

map<int, int> mapset;

void dfs(int col, int row, int m, int n, int cell) {
	int_board[col][row] = 0;
	bool_board[col][row] = false;
	if (mapset.find(cell) != mapset.end()) mapset[cell]++;
	else {
		mapset[cell] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		int my = col + dy[i];
		int mx = row + dx[i];
		if ((0 <= mx && mx < n) && (0 <= my && my < m) && cell == int_board[my][mx] && bool_board[my][mx] == true)dfs(my, mx, m, n, cell);

	}
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<pair<int, int>> v;
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
			int key = int_board[col][row];
			dfs(col, row, m, n, int_board[col][row]);
			v.push_back(make_pair(key, mapset[key]));
			mapset[key] = 0;
		}
	}
	sort(v.begin(),v.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
		});
	vector<int> answer(2);
	answer[0] = v.size();
	answer[1] = v.front().second;
	return answer;
}
