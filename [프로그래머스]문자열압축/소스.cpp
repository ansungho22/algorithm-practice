#include <string>
#include<iostream>
#include<algorithm>


using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++) {
        string StrConvert, Temp;

        int cnt = 1;
        Temp = s.substr(0, i);

        for (int j = i; j < s.size(); j += i) {
            if (Temp == s.substr(j, i)) cnt++;
            else {
                if (cnt > 1) {
                    StrConvert += to_string(cnt);
                }
                StrConvert += Temp;
                Temp = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1) StrConvert += to_string(cnt);

        StrConvert += Temp;
        answer = min(answer, int(StrConvert.size()));
    }
    return answer;
}