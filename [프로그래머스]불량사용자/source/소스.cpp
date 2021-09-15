#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> user;
vector<string> banned;
bool visited[9] = {false,};
set<string> s;

void serch(int index) {
    if (index == banned.size()) {
        string banned_user = "";
        for (int i = 0; i < user.size(); i++) {
            if (visited[i]) {
                banned_user += user[i];
            }
        }
        s.insert(banned_user);
        return;
    }
    for (int i = 0; i < user.size(); i++) {
        bool isTrue = true;
        if (visited[i]) {
            continue;
        }
        if (user[i].length() != banned[index].length()) {
            continue;
        }
        for (int j = 0; j < user[i].length(); j++) {
            if (banned[index][j] == '*') {
                continue;
            }
            if (banned[index][j] != user[i][j]) {
                isTrue = false;
                break;
            }
        }
        if (isTrue) {
            visited[i] = true;
            serch(index + 1);
            visited[i] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user = user_id;
    banned = banned_id;
    serch(0);
    answer = s.size();
    return answer;
}
