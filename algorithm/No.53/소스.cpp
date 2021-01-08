#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

struct fish
{
	int dist;
	int x;
	int y;
};

bool compare(fish a,fish b){
	if (a.dist == b.dist) {
		if (a.y == b.y) {
			return a.x > b.x;
		}
		return a.y > b.y;
	}
	return a.dist > b.dist;
}