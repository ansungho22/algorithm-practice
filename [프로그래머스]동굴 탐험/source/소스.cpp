#include <string>
#include <vector>
#include <map>
#include <iostream>
#define MAX 200000

using namespace std;

vector<int> v[MAX];
int lock[MAX] = { 0, };
bool visited[MAX] = { 0, };
map <int, int> mlock;

void DFS(int node)
{
	if (visited[node])    return;
	if (mlock.find(node) != mlock.end())
	{
		int pre = mlock[node];
		if (!visited[pre])
		{
			lock[pre] = node;
			return;
		}
	}
	visited[node] = true;
	DFS(lock[node]);
	for (int i = 0; i < v[node].size(); i++)    DFS(v[node][i]);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	bool answer = true;

	for (auto tmp : path)
	{
		v[tmp[0]].push_back(tmp[1]);
		v[tmp[1]].push_back(tmp[0]);
	}

	for (auto tmp : order)    mlock.insert(make_pair(tmp[1], tmp[0]));

	if (mlock.find(0) != mlock.end())   return false;

	visited[0] = true;
	for (int node : v[0]) DFS(node);

	for (int i = 0; i < n; i++)    if (!visited[i]) answer = false;

	return answer;
}

int main() {
	int n = 9;
	vector<vector<int>> path = { {0, 1},{0, 3},{0, 7},{8, 1},{3, 6},{1, 2},{4, 7},{7, 5}};
	vector<vector<int>> order = { {8,5} ,{6,7},{4,1} };
	cout << solution(n,path,order);
}