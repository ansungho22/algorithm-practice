//น้มุ 2667
#include<vector>
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = { 0,0,1,-1 };
int N,ans=0;
int board[25][25] = { 0 };

void dfs(int y,int x) {
	int mx, my;
	if (board[y][x] == 0)return;
	else {
		board[y][x] = 0;
		ans++;
	}
	for (int i = 0; i < 4; i++)
	{
		mx = x + dx[i];
		my = y + dy[i];
		if (mx < 0 || mx >= N || my < 0 || my >= N )continue;
		dfs(my, mx);
	}
}
int main() {
	string temp;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			board[i][j] = temp[j]-'0';
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1) {
				dfs(i, j);
				v.push_back(ans);
				ans = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for(auto i : v){
		cout << i << endl;
	}
}