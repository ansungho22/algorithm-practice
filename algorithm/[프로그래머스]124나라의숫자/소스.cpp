//프로그래머스 124 나라의 숫자

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> v;
    v.push_back(n);
    while (n > 4) {
        n = (n - 1) / 3;
        v.push_back(n);
    }
    if (v.back() == 3) answer += to_string(4);
    else answer += to_string(v.back());
    
    while (v.size() != 1) {
        int temp = 0;
        int num = v.back();
        v.pop_back();
        temp = v.back() - (num * 3);
        if (temp == 3) temp = 4;
        answer += to_string(temp);

    }
    return answer;
}
int main() {
    cout << solution(4);
}