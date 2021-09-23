#include <string>
#include <vector>
using namespace std;

int adj[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 10000000;

    for (int i = 1; i <= n; i++) adj[i][i] = 0;
    for (auto v : fares) {
        adj[v[0]][v[1]] = v[2];
        adj[v[1]][v[0]] = v[2];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);

    answer = 1e9;

    for (int i = 1; i <= n; i++)
        answer = min(answer, adj[s][i] + adj[i][a] + adj[i][b]);

    return answer;
}