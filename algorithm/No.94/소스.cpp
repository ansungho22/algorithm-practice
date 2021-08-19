#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string answer = "";
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<string> TileRefresh(char Tile, vector<string> board) {
	vector<string> NewBoard = board;
	if (Tile == '0') return NewBoard;
	answer += Tile;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == Tile)NewBoard[i][j] = '.';
		}
	}
	return NewBoard;
}

char TilesStuck(vector<string> board, int m, int n) {
	vector<char> RemoveTilesList;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int h = 0; h < 4; h++)
			{
				if (board[i][j] == '.' || board[i][j] == '*')
				{
					continue;
				}
				if (
					((i + dy[h] >= 0) && (i + dy[h] < m)) &&
					((j + dx[h] >= 0) && (j + dx[h] < n)) &&
					board[i][j] == board[i + dy[h]][j + dx[h]]
				   )
				{
					RemoveTilesList.push_back(board[i][j]);
					board[i][j] = '.';
					board[i + dy[h]][j + dx[h]] = '.';
				}
			}
		}
	}
	sort(RemoveTilesList.begin(), RemoveTilesList.end());
	if (RemoveTilesList.empty())return '0';

	return RemoveTilesList.front();
}

char TilesOff(vector<string> board, int m, int n) {
	vector<string> RemoveTilesList;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int h = 0; h < 4; h++)
			{
				if (board[i][j] == '.' || board[i][j] == '*')
				{
					continue;
				}

			}
		}
	}


	return 0;
}

string solution(int m, int n, vector<string> board) {
	vector<string> Tile = board;
	Tile = TileRefresh(TilesStuck(board, m, n), Tile);
	if (answer == "")answer = "IMPOSSIBLE";
	return answer;
}
