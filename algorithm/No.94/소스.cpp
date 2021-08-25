#include <string>
#include <vector> 
#include <cstring>
using namespace std;

struct pos {
	int x, y; 
};

int M, N;

vector<string> m_board;
vector<vector<pos>> alpha_pos;

int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };

bool reachable(char c, pos from, pos to)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = from.x + dr_x[i];
		int ny = from.y + dr_y[i];
		while (!(nx < 0 || nx >= M || ny < 0 || ny >= N))
		{
			if (nx == to.x && ny == to.y) return true;
			if (m_board[nx][ny] != '.') break; 
			for (int j = ((i + 1) % 2); j < 4; j += 2)
			{
				int nnx = nx + dr_x[j];
				int nny = ny + dr_y[j];
				while (!(nnx < 0 || nnx >= M || nny < 0 || nny >= N))
				{
					if (nnx == to.x && nny == to.y) return true; 
					if (m_board[nnx][nny] != '.') break;
					nnx += dr_x[j]; 
					nny += dr_y[j];
				}
			}
			nx += dr_x[i];
			ny += dr_y[i];
		}
	} return false;
}
bool game(string& answer, int alpha_cnt)
{
	while (true) 
	{
		bool match = false;
		for (int i = 0; i < 26; ++i) 
		{
			if (!alpha_pos[i].empty()) 
			{
				char c = i + 'A';
				pos from = alpha_pos[i][0];
				pos to = alpha_pos[i][1];
				if (reachable(c, from, to)) 
				{
					answer += c;
					m_board[from.x][from.y] = '.';
					m_board[to.x][to.y] = '.';
					alpha_pos[i].clear();
					match = true;
					alpha_cnt -= 2;
					break;
				}
			}
		}
		if (!match) break;
	}
	return (alpha_cnt == 0);
}
string solution(int m, int n, vector<string> board)
{
	M = m;
	N = n;
	m_board = board;
	alpha_pos = vector<vector<pos>>(26);
	int alpha_cnt = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (isalpha(board[i][j]))
			{
				alpha_cnt++;
				alpha_pos[board[i][j] - 'A'].push_back({ i, j });
			}
		}
	}
	string answer = "";
	if (game(answer, alpha_cnt)) return answer;
	return "IMPOSSIBLE";
}

