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

//백준7576번 토마토 파이썬
//import sys
//from collections import deque
//read = sys.stdin.readline
//X, Y = map(int, read().split())
//box = []
//loc = deque()
//for i in range(Y) :
//	row = list(map(int, read().split()))
//	for j in range(X) :
//		if row[j] == 1 :
//			loc.append([i, j])
//			box.append(row)
//
//			dx = [-1, 0, 1, 0]
//			dy = [0, 1, 0, -1]
//			cnt = 1
//			while loc:
//y, x = loc.popleft()
//
//for l in range(4) :
//	move_x = x + dx[l]
//	move_y = y + dy[l]
//
//	if move_x < 0 or move_y < 0 or move_x >= X or move_y >= Y or box[move_y][move_x] == -1 :
//		continue
//
//		if box[move_y][move_x] == 0 :
//			box[move_y][move_x] = box[y][x] + 1
//			loc.append([move_y, move_x])
//			cnt = box[move_y][move_x]
//
//			fuck = True
//			for k in box :
//if 0 in k :
//print(-1)
//fuck = False
//break
//
//if fuck == True :
//	if cnt == 1 :
//		print(0)
//		elif cnt != 1 :
//		print(cnt - 1)
