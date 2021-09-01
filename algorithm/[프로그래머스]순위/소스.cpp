// 프로그래머스 순위
#include <string>
#include <vector>

using namespace std;

bool ch[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (auto x : results) ch[x[0]][x[1]] = true;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ch[i][k] && ch[k][j]) ch[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (ch[i][j] || ch[j][i]) cnt++;
        }
        if (cnt == n - 1) answer++;
    }
    return answer;
}