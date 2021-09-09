//프로그래머스 등굣길
#include <vector>
#include<iostream>
using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
	int puddles_map[101][101] = { 0, };
	int map[101][101] = { 0, };

	// set puddles into puddles_map.
	for (auto v : puddles)
		puddles_map[v[1]][v[0]] = -1;

	map[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (puddles_map[i][j] == -1)
				map[i][j] = 0;
			else
				map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
		}
	}
	return map[n][m];
}
int main() {
	int m = 4, n = 3;
	vector<vector<int>> puddles = { {2,2} };
	cout << solution(m, n, puddles);
}
