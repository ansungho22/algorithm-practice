#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;
bool possi(vector<int>& vec, int now) {
    for (int i = 0; i < vec.size(); i++)
        if ((vec[i] & now) == vec[i])return false;
    return true;
}
int solution(vector<vector<string>> relation) {
    int n = relation.size();
    int m = relation[0].size();
    vector<int> ans;
    cout << (1 << m);
    for (int i = 1; i < (1 << m); i++) {
        set<string> s;
        for (int j = 0; j < n; j++) {
            string now = "";
            for (int k = 0; k < m; k++) {
                if (i & (1 << k))now += relation[j][k];
            }
            s.insert(now);
        }
        if (s.size() == n && possi(ans, i))ans.push_back(i);
    }
    return ans.size();
}
int main() {
    vector<vector<string>> relation = { {"100","ryan","music","2"} ,{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };
    cout << solution(relation);
}