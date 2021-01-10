//프로그래머스 k번째수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto i : commands) {
        int start = i[0]-1;
        int end = i[1];
        int num = i[2] - 1;
        vector<int> v;
        v.assign(array.begin() + start, array.begin() + end);
        sort(v.begin(), v.end());
        answer.push_back(v[num]);
    }
    return answer;
}
int main() {
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
    vector<int> ans = solution(array, commands);
    for (auto i : ans) {
        cout << i << " ";
    }
}