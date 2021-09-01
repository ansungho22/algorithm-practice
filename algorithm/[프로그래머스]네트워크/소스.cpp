//네트워크
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int com[200][200] = { 0, };
void dfs(int i,int j,int n) {
	com[i][j] = 0;
	com[j][i] = 0;
	for (int visit = 0; visit < n; visit++)
	{
		if (com[i][visit] == 1)dfs(visit,i, n);
	}
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			
			com[i][j] = computers[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (com[i][j] == 1) {
				answer++;
				dfs(i, j,n);
			}
		}
	}
    return answer;
}
int main() {
	int n = 3;
	vector<vector<int>> computers = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
	cout << solution(n, computers);
}