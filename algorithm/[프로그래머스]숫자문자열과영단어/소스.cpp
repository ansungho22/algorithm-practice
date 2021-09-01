#include <string>
#include <vector>
#include <iostream>
using namespace std;


char StringToint(string s) {
    if (s == "one") return '1';
    else if (s == "two") return '2';
    else if (s == "three") return '3';
    else if (s == "four") return '4';
    else if (s == "five") return '5';
    else if (s == "six") return '6';
    else if (s == "seven") return '7';
    else if (s == "eight") return '8';
    else if (s == "nine") return '9';
    else if (s == "zero") return '0';
    else {
        return 'a';
    }

}

int solution(string s) {
    string answer = "";
    string EnNum = "";
    for (char i : s) {
        if (i - '0' < 10) {
            answer += i;
        }
        else {
            EnNum += i;
            if (StringToint(EnNum) - '0' < 10) {
                answer += StringToint(EnNum);
                EnNum = "";
            }
        }
    }
    return stoi(answer);
}
int main() {
    string s = "one4seveneight333";
    cout << solution(s);
}