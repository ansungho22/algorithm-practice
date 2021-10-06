#include <set>
#include <vector>
#define has(a) (building.find(pred[(a)])!=building.end())
using namespace std;

bool isValid(const set<vector<int>>& building) {
    for (auto build : building) {
        int x = build[0], y = build[1], a = build[2];

        if (a == 0) {
            vector<int> pred[3] = { {x,y - 1,0},{x,y,1},{x - 1,y,1} };
            if (y == 0 || has(0) || has(1) || has(2)) continue;
            return false;
        }
        else {
            vector<int> pred[4] = { {x,y - 1,0},{x + 1,y - 1,0},{x + 1,y,1},{x - 1,y,1} };
            if (has(0) || has(1) || (has(2) && has(3))) continue;
            return false;
        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> building;

    for (auto task : build_frame) {
        vector<int> v = { task[0],task[1],task[2] };
        if (task[3] == 0) {
            building.erase(v);
            if (!isValid(building)) building.insert(v);
        }
        else {
            building.insert(v);
            if (!isValid(building)) building.erase(v);
        }
    }

    for (auto build : building)
        answer.push_back(build);

    return answer;
}