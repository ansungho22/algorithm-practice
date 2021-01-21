//단어변환
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool cmp(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
        if (cnt > 1)return false;
    }
    return true;
}
bool str_find(string a, vector<string> v) {
    for (auto i : v) {
        if (a == i)return false;
    }
    return true;
}
int dfs(string begin, string target, vector<string> words, vector<bool> visit,int answer) {
    if (cmp(begin,target))return answer+1;
    for (int i = 0; i < words.size(); i++)
    {
        if (visit[i] != true) {
            if (cmp(begin, words[i])) {
                visit[i] = true;
                answer++;
                return dfs(words[i], target, words, visit, answer);
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    vector<bool> visit(words.size());
    int answer = 0;
    if (str_find(target, words))return 0;
    answer = dfs(begin, target, words, visit, answer);
    return answer;
}
int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution(begin, target, words);
}