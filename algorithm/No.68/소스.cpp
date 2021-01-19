//¿ß¿Â
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string, int> m;
    for (auto i : clothes) {
        if (m.find(i[1]) != m.end()) {
            m[i[1]] += 1;
            continue;
        }
        m.insert(make_pair(i[1], 2));
    }
    map<string, int> ::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        answer *= it->second;
    }
    return --answer;
}
int main() {
    vector<vector<string>> clothes = { {"yellow_hat", "a" }, {"blue_sunglasses", "b"},{"green_turban", "c"} };
    cout << solution(clothes);
}