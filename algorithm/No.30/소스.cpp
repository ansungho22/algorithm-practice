//백준 7569번 토마토
#include<iostream>
#include<queue>
using namespace std;
#define MAX 101
int box[MAX][MAX][MAX] = { 0, };
int ans = 1;
queue<pair<int, pair<int, int>>> que;
int vx[6] = { 1,-1,0,0,0,0 };
int vy[6] = { 0,0,1,-1,0,0 };
int vh[6] = { 0,0,0,0,1,-1 };
void bfs(int h,int y,int x) {
	while (!que.empty()) {
		int H = que.front().first;
		int Y = que.front().second.first;
		int X = que.front().second.second;
		que.pop();
		for (int i = 0; i < 6; i++)
		{
			int M_H = H + vh[i];
			int M_Y = Y + vy[i];
			int M_X = X + vx[i];
			if (M_H < 0 || M_H >= h ||
				M_Y < 0 || M_Y >= y ||
				M_X < 0 || M_X >= x || box[M_H][M_Y][M_X]== -1)continue;
			if (box[M_H][M_Y][M_X] == 0) {
				box[M_H][M_Y][M_X] = box[H][Y][X] + 1 ;
				ans = box[M_H][M_Y][M_X];
				que.push(make_pair(M_H, make_pair(M_Y, M_X)));
			}
		}

	}
}
int main() {
	int Y, X, H,input;
	cin >> X >> Y >> H;
	for (int h = 0; h < H; h++){
		for (int y = 0; y < Y; y++){
			for (int x = 0; x < X; x++){
				cin >> input;
				box[h][y][x]=input;
				if (input == 1) {
					que.push(make_pair(h,make_pair(y, x)));
				}
			}
		}
	}
	bfs(H, Y, X);
	for (int h = 0; h < H; h++) {
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				
				if (box[h][y][x] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	if (ans == 1) {
		cout << 0;
		return 0;
	}
	else {
		cout << ans-1;
		return 0;
	}
}