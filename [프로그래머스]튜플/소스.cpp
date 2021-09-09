#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> m;
void map_add(string s) {
    if (m.find(s) == m.end()) m[s] = 1;
    else {
        m[s]++;
    }
}
vector<int> solution(string s) {
    vector<int> answer;
    string str="";
    for (auto i : s) {
        if (i == '{' || i == '}') continue;
        if (i == ',')
        {
            map_add(str);
            str = "";
            continue;
        }
        str += i;
    }
    map_add(str);

    vector<pair<string, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
        });
    for (auto i : v) {
        answer.push_back(stoi(i.first));
    }
    return answer;
}

int main() {
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    for (auto i : solution(s)) {
        cout << i;
    }
}