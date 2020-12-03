//구름 최단거리 구하기
#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
#define MAX 100
using namespace std;
int N;
int arr[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { false };
int vx[4] = { 1,-1,0,0 };
int vy[4] = { 0,0,1,-1 };

int bfs(int x, int y,int cnt) {
	queue <pair<pair<int, int>, int>> que;
	que.push(make_pair(make_pair(x, y), cnt));

	while (!que.empty()) {
		x = que.front().first.first;
		y = que.front().first.second;
		cnt = que.front().second;
		que.pop();

		if (x == N - 1 && y == N - 1)return cnt;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + vx[i];
			int ny = y + vy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
			if (arr[nx][ny] == 1 && !visit[nx][ny]) {
				visit[nx][ny] = true;
				que.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
	
	
	

}

int main() {
	cin >> N;
	for (int i = 0; i< N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		
		}
	}
	visit[0][0] = true;
	cout << bfs(0, 0, 1);
	return 0;
	
}