//여행경로
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string> > m;

    sort(tickets.begin(), tickets.end(), greater< vector<string> >());

    for (int i = 0; i < tickets.size(); i++) {
        m[tickets[i][0]].push_back(tickets[i][1]);
    }

    vector<string> s{ "ICN" };

    while (!s.empty()) {
        string airport = s.back();
        if (m.find(airport) == m.end() || m[airport].size() == 0) {
            answer.push_back(airport);
            s.pop_back();
        }
        else {
            s.push_back(m[airport].back());
            m[airport].pop_back();
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

