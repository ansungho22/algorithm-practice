#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> v;
void dfs(int (*borad)[10], bool (*T_Fborad)[10], int x, int y,int n) {
	if (borad[x][y] == 0 || x>=n || y>=n || x < 0 || y < 0 )return;
	if (x == n - 1 && y == n - 1)v.push_back(borad[x][y]);
	int vx[] = { 1,-1,0,0 };
	int vy[] = { 0,0,1,-1 };
	T_Fborad[x][y] = true;
	for (int i = 0; i < n; i++)
	{
		if (borad[x + vx[i]][y + vy[i]] != 0 && T_Fborad[x + vx[i]][y + vy[i]]==false) {
			borad[x + vx[i]][y + vy[i]] = borad[x][y] + 1;
			dfs(borad, T_Fborad, x + vx[i], y + vy[i], n);
		}
	}
	

}

int main() {
	int N;
	int input;
	int borad[10][10] = { 0 };
	bool T_Fborad[10][10]{ false };
	cin >> N;
	for (int i = 0; i< N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> borad[i][j];
		
		}
	}
	dfs(borad, T_Fborad, 0,0, N);
	sort(v.begin(), v.end());
	cout << v.front();
	
}