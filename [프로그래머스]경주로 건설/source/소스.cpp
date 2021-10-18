#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;
unsigned int visited[25][25][4];
int dy[] = { 1, 0, -1, 0 }; //down, right, up, left
int dx[] = { 0, 1, 0, -1 };
unsigned int result = -1;

void dfs(vector<vector <int>>& map, int N, int y, int x, int dir, unsigned int cur_cost) {
    if (y < 0 || y >= N || x < 0 || x >= N || map[y][x] == 1 || visited[y][x][dir] < cur_cost) {
        return;
    }
    visited[y][x][dir] = cur_cost;
    if (y == N - 1 && x == N - 1) {
        if (result > cur_cost) {
            result = cur_cost;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int dirIdx = (dir + i) % 4;
        int ny = y + dy[dirIdx];
        int nx = x + dx[dirIdx];
        if (i == 0) {
            dfs(map, N, ny, nx, dirIdx, cur_cost + 100);
        }
        else {
            dfs(map, N, ny, nx, dirIdx, cur_cost + 600);
        }
    }

}
int solution(vector<vector<int>> board) {
    memset(visited, INT_MAX, sizeof(visited));
    dfs(board, board[0].size(), 0, 0, 0, 0);
    dfs(board, board[0].size(), 0, 0, 1, 0);
    return result;
}
int main() {
    vector<vector<int>> board = { {0,0,0 }, { 0,0,0 }, { 0,0,0 }};
    cout << solution(board);
}