//프로그래머스 소수 찾기
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;
bool prm[10000000] = { false };

void prime_number(int n) {
    if (n <= 1) return;
    for (int i = 2; i <= n; i++) {
        prm[i] = true;
    }
    for (int i = 2; i * i <= n; i++) {
        if (prm[i]) {
            for (int j = i * i; j <= n; j += i)
                prm[j] = false;
        }
    }
}
int check_num(int max, int num, vector<int> input_num) {
    int digit = 0;
    vector<int> prime;
    string str = to_string(num);
    sort(str.begin(), str.end());
    for (int i = 0; i < str.size(); i++) {
        int num = str[i] - '0';
        prime.push_back(num);
    }
    for (int i = 0; i < prime.size(); i++) {
        for (int j = 0; j < input_num.size(); j++) {
            if (prime[i] == input_num[j]) {
                digit++;
                input_num[j] = -1;
                break;
            }
        }
    }
    if (digit == prime.size()) return 1;
    else return 0;
}
int solution(string numbers) {
    int answer = 0;
    int max_num = 0;
    int num = 0;
    string str;
    vector<int> input_num;
    for (int i = 0; i < numbers.size(); i++) {
        num = numbers[i] - '0';
        input_num.push_back(num);
    }
    sort(input_num.begin(), input_num.end());
    for (int i = input_num.size() - 1; i >= 0; i--) {
        max_num += input_num[i] * pow(10, i);
    }
    prime_number(max_num);
    for (int i = 2; i <= max_num; i++) {
        if (prm[i] == true) {
            if (check_num(max_num, i, input_num))answer++;
        }
    }
    return answer;
}
int main() {
    string str = "110";
    cout << solution(str);
}