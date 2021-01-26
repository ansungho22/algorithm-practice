//프로그래머스 가장 먼 노드
#include <string>
#include <vector>
#include<queue>
using namespace std;

int d[20001][20001];
bool visit[20001];
int dist[20001];
int solution(int n, vector<vector<int>> edge) {
    int max = 0;
    int answer = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        d[edge[i][0]][edge[i][1]] = 1;
        d[edge[i][1]][edge[i][0]] = 1;
    }
    queue<int> q;
    visit[1] = true;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int first = q.front();
        q.pop();
        for (int i = 2; i <= n; i++)
        {
            if (d[first][i] == 1 && !visit[i])
            {
                q.push(i);
                visit[i] = true;
                dist[i] = dist[first] + 1;
                if (max < dist[i])
                {
                    max = dist[i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (max == dist[i])
        {
            answer++;
        }
    }
    return answer;
}