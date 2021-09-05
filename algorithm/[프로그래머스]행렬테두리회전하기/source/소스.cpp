#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int board[102][102] = { 0, };

int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };
deque<pair<int, int>> loc;

vector<pair<int, int>> Edge(vector<int> v) { 
	vector<pair<int, int>> Edges;
	Edges.push_back(make_pair(v[0], v[3]));
	Edges.push_back(make_pair(v[2], v[3]));
	Edges.push_back(make_pair(v[2], v[1]));
	Edges.push_back(make_pair(v[0], v[1]));
	return Edges;
}

deque<int> outline(vector<int> queries) {
	deque<int> outlines;
	vector<pair<int, int>> Edges = Edge(queries);

	int col = queries[0];
	int row = queries[1];
	
	int i = 0;
	while (true) {
		outlines.push_back(board[col][row]);
		loc.push_back(make_pair(col, row));
		col = col + my[i];
		row = row + mx[i];
		if (col == queries[0] && row == queries[1])break;
		if (col == Edges[i].first && row == Edges[i].second) {
			i++;
		}
	}
	outlines.push_front(outlines.back());
	outlines.pop_back();
	return outlines;
}
void rotation(deque<int> outline_num) {
	for (int i = 0; i < loc.size(); i++)
	{
		board[loc[i].first][loc[i].second] = outline_num[i];
	}
}
vector<int> solution(int columns, int rows, vector<vector<int>> queries) {
	vector<int> answer;
	int num = 1;
	for (int col = 1; col <= columns; col++)
	{
		for (int row = 1; row <= rows; row++)
		{
			board[col][row] = num++;
		}
	}
	for (auto query : queries) {
		deque<int> dq = outline(query);
		rotation(dq);
		sort(dq.begin(), dq.end());
		answer.push_back(dq.front());
		loc.clear();
	}

	return answer;
}
