//킹 나이트 체스
#include<iostream>
#include<vector>
using namespace std;
int dx[] = { 1,-1,0,0,1,1,-1,-1,2,2,-2,-2,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1,1,-1,1,-1,2,-2,2,-2 };
long long borad[100][100] = { 0, };
long long howMany(int size, vector<int> start, vector<int>end, int numMoves) {
	vector<vector<pair<int, int>>> v;
	v.reserve(numMoves);
	vector<pair<int, int>> temp;
	temp.push_back(make_pair(start[0], start[1]));
	v.push_back(temp);
	temp.clear();
	for (int i = 1; i <= numMoves; i++)
	{
		for (int j = 0; j < v[i-1].size(); j++)
		{
			int y = v[i - 1][j].first;
			int x = v[i - 1][j].second;
			for (int k = 0; k < 16; k++)
			{
				int mx = x + dx[k];
				int my = y + dy[k];
				if (mx <0 || mx > (size - 1) || my<0 || my > (size - 1))continue;
				borad[my][mx]++;
				temp.push_back(make_pair(mx, my));
			}
		}
		v.push_back(temp);
		temp.clear();
	}
	return borad[end[0]][end[1]];
}

int main() {
	int size = 3;
	vector<int> start = { 0,0 };
	vector<int> end = { 0,0 };
	int numMoves = 2;
	cout << howMany(size, start, end, numMoves);
}