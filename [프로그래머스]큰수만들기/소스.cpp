//큰 수 만들기
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    int size = number.size();
    string answer = number.substr(k);
    int cur = k;
    int ans_cur = 0;
    int serch = 0;
    int temp = 0;
    while (1) {
        for (int i = cur; i >= serch; i--) {
            if (number[i] >= answer[ans_cur]) {
                answer[ans_cur] = number[i];
                temp = i + 1;
            }
        }
        serch = temp;
        ans_cur++;
        cur++;
        if (serch == cur)break;
    }
    return answer;
}
int main() {
    string number = "00100";
    int k = 2;
    cout << solution(number, k);
}

//string solution(string number, int k) {
//    string answer = "";
//    answer = number.substr(k);
//    for (int i = k - 1; i >= 0; i--) {
//        int j = 0;
//        do {
//            if (number[i] >= answer[j]) {
//                char temp = answer[j];
//                answer[j] = number[i];
//                number[i] = temp;
//                j++;
//            }
//            else {
//                break;
//            }
//        } while (1);
//    }
//
//
//
//    return answer;
//}