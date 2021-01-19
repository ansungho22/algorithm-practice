//완주하지 못한 선수
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    map<string, int> ::iterator it;
    for (auto i : participant) {
        if (m.find(i) != m.end()) {
            m[i] += 1;
            continue;
        }
        m.insert(make_pair(i, 1));
    }
    for (auto i : completion) {
        if (m.find(i) != m.end()) {
            if (m[i] == 1)m.erase(i);
            else m[i] -=1;
        }
    }
    it = m.begin();
    answer = it->first;
    return answer;
}
