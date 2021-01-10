//프로그래머스 가장큰수
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_v;
    for (auto i : numbers) {
        str_v.push_back(to_string(i));
    }
    sort(str_v.begin(), str_v.end(), cmp);
    for (auto i : str_v) {
        answer += i;
    }
    if (answer.front() == '0')return "0";
    return answer;
}
int main() {
    vector<int> num = { 3,30,34,5,9 };
    cout << solution(num);
}