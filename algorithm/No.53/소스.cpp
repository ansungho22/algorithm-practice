#include<iostream>
#include<vector>
#include<queue>
#include <string.h>
using namespace std;
int N;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int board[20][20] = { 0, };
bool visit[20][20] = { false, };
struct compare {
	bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		if (a.second == b.second)
		{
			if (a.first.first == b.first.first)
			{
				return a.first.second > b.first.second;
			}
			return a.first.first > b.first.first;
		}
		return a.second > b.second;
	}
};

queue<pair<pair<int, int>, int>> q;//아기상어의 움직임


void dfs() {
	int ans = 0;
	int eat = 0;
	int size = 2;
	while (1) {
		priority_queue < pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> pq; // 아기상어의 먹이 que
		while (!q.empty()) {
			int cur_x = q.front().first.second;
			int cur_y = q.front().first.first;
			int dist = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int mx = cur_x + dx[i];
				int my = cur_y + dy[i];
				if (mx < 0 || mx >= N || my<0 || my >= N )continue;
				if (board[my][mx] > size || visit[my][mx])continue;
				q.push(make_pair(make_pair(my, mx), dist + 1));
				visit[my][mx] = true;
				if (board[my][mx] != 0 && board[my][mx] < size)pq.push(make_pair(make_pair(my, mx), dist + 1));

			}
		}
		memset(visit, false, sizeof(visit));
		if (!pq.empty()) {
			int cur_x = pq.top().first.second;
			int cur_y = pq.top().first.first;
			int dist = pq.top().second;
			pq.pop();
			board[cur_y][cur_x] = 0;
			eat++;
			ans += dist;
			dist = 0;
			q.push(make_pair(make_pair(cur_y, cur_x), dist));
			visit[cur_y][cur_x] = true;
		}
		else {
			cout << ans << endl;
			break;
		}
		if(eat == size){
			size++;
			eat = 0;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9) {
				q.push(make_pair(make_pair(i, j), 0));
				board[i][j] = 0;
				visit[i][j] = true;
			}
		}
	}
	dfs();
	return 0;
}