//baekjoon 1012

#include<algorithm>
#include<stdlib.h>
#include <iostream>
#include<vector>
using namespace std;
int A[52][52] = { 0, };
int vx[] = { 0,0,-1,1 };
int vy[] = { 1,-1,0,0 };
void dfs(int a, int b) {
	if (A[a][b] == 0)return;
	A[a][b] = 0;
	for (int i = 0; i < 4; i++)
	{
		dfs(a + vx[i], b + vy[i]);
	}
}
void input() {
	int row, col, bug = 0;
	int ans = 0;
	int x, y = 0;
	cin >> row >> col >> bug;

	for (int i = 0; i < bug; i++)
	{
		cin >> x >> y;
		A[x][y] = 1;
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j  < 50; j ++)
		{
			if (A[i][j] == 1) 
			{
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
}

int main() {
	int test_case;

	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		input();
	}
	

}