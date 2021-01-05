// น้มุ 2583น๘
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int board[101][101] = { 0, };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int temp = 0;
void dfs(int x, int y,int M,int N) {
	int mx, my;
	if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 1) return;
	temp++;
	board[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		mx = x + dx[i];
		my = y + dy[i];
		dfs(mx, my, M, N);
	}
	return ;
}
int main() {
	int N, K, M,start_x,start_y,end_x,end_y;
	vector<int> v;
	int ans = 0;
	cin >> M >> N >> K; // N = X ,M = Y
	for (int i = 0; i < K; i++)
	{
		cin >> start_x >> start_y >> end_x >> end_y;
		for (int i = start_x; i < end_x; i++)
		{
			for (int j = start_y; j < end_y; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0;  j < N;  j++)
		{
			if (board[j][i] == 0) {
				ans++;
				dfs(j, i, M, N);
				v.push_back(temp);
				temp = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (auto i : v) {
		cout << i << " ";
	}
}