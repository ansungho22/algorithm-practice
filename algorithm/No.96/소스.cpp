#include <string>
#include <vector>
#include <iostream>

using namespace std;

int a_cnt(string str) {
    int answer = 0;
    for (auto i : str) {
        if (i == 'a')answer++;
    }
    return answer;
}

vector<bool> solution(vector<string> a) {
    vector<bool> answer;
    for (string& i : a) {
        int cnt = 0;
        int alpha_a = a_cnt(i);
        if (i == "a" || alpha_a == i.size()) {
            answer.push_back(true);
            continue;
        }
        if (alpha_a == 0) {
            answer.push_back(false);
            continue;
        }
        while (true) {
            if (i[0] == 'b' && i[i.length() - 1] == 'b' ) {
                i.erase(0, 1);
                i.erase(i.length() - 1, 1);
                cnt++;
            }
            else if ((i[0] == 'a' || i[i.length() - 1] == 'a') && alpha_a > 1) {
                if (cnt > 0) {
                    if (alpha_a != cnt) {
                        answer.push_back(false);
                        break;
                    }
                    cnt = 0;
                }
                if (i[0] == 'a' && alpha_a > 1) {
                    i.erase(0, 1);
                    alpha_a--;
                }
                else if (i[i.length() - 1] == 'a' && alpha_a > 1) {
                    i.erase(i.length() - 1, 1);
                    alpha_a--;
                }
            }
            else if (cnt > 0) {
                if (alpha_a != cnt) {
                    answer.push_back(false);
                    break;
                }
                cnt = 0;
            }
            else if (i == "a" && i.length() == 1 && cnt == 0) {
                answer.push_back(true);
                break;
            }
            else {
                answer.push_back(false);
                break;

            }
        }
    }
    return answer;
}