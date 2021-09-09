//백준 2606번 바이러스
#include<iostream>
#include<queue>
using namespace std;
#define MAX 101
bool computer[MAX][MAX] = {false,};
int check[MAX] = { 0, };
queue <int> que;

int bfs(int n) {
	int node;
	int ans = -1;
	while (!que.empty()) {
		ans++;
		node = que.front();
		que.pop();
		for (int i = 1; i <= n; i++)
		{
			if (computer[node][i] == true && check[i] == 0 ) {
				check[i] = 1;
				que.push(i);
			}
		}
	}
	
	return ans;
}
int main() {
	int N;
	int cnt;
	int x, y;
	check[1] = 1;
	cin >> N >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> x >> y;
		computer[x][y] = true;
		computer[y][x] = true;
	}
	que.push(1);
	cout << bfs(N);
	
	return 0;
}