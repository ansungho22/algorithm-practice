#include <string>
#include <vector>
#include <list>
#include <limits.h>
#include <iostream>
using namespace std;
void DFS(vector<list<int> >& tree, vector<int>& minPick, vector<int>& minNoPick, vector<int>& sales, int cur)
{
    for (auto& member : tree[cur])
    {
        DFS(tree, minPick, minNoPick, sales, member);
    }

    minPick[cur] = sales[cur - 1];
    minNoPick[cur] = 0;

    for (auto& member : tree[cur])
        minPick[cur] += min(minNoPick[member], minPick[member]);

    int noPick = INT_MAX;
    for (auto& member : tree[cur])
    {
        int sum = minPick[member];
        for (auto& other : tree[cur])
        {
            if (other == member)
                continue;
            sum += min(minPick[other], minNoPick[other]);
        }
        noPick = min(sum, noPick);
    }
    if (noPick != INT_MAX)
        minNoPick[cur] = noPick;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;

    int n = sales.size();

  
    vector<list<int> >  tree(n + 1);

    for (auto& link : links)
        tree[link[0]].push_back(link[1]);

 
    vector<int>     minPick(n + 1, 0);
    vector<int>     minNoPick(n + 1, 0);

    DFS(tree, minPick, minNoPick, sales, 1);

    answer = min(minPick[1], minNoPick[1]);

    return answer;
}

int main() {
    vector<int> sales = { 14, 17, 15, 18, 19, 14, 13, 16, 28, 17 };
    vector<vector<int>> links = { {10, 8} ,{1, 9},{9, 7},{5, 4},{1, 5},{5, 10},{10, 6},{1, 3},{10, 2} };
    cout << solution(sales, links);
}