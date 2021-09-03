#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool flag;
bool visited[5][5];
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

bool inRange(int y, int x) {
    return y >= 0 && y < 5 && x >= 0 && x < 5;
}

void dfs(int y, int x, vector<string>& board, int depth) {
    if (flag || depth > 2) return;
    if (depth > 0 && board[y][x] == 'P') {
        flag = true;
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!inRange(ny, nx) || visited[ny][nx] || board[ny][nx] == 'X')
            continue;
        dfs(ny, nx, board, depth + 1);
    }
}
bool solve(vector<string>& board) {
    vector<pair<int, int>> people;
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++)
            if (board[i][j] == 'P') people.push_back({ i,j });

    for (auto pii : people) {
        flag = false;
        memset(visited, false, sizeof(visited));
        dfs(pii.first, pii.second, board, 0);
        if (flag) return false;
    }

    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto b : places) {
        if (solve(b)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}