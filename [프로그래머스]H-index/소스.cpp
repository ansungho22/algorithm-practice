#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 프로그래머스 h-index
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        if (citations.size() - i <= citations[i]) { // 남은 논문의 수 <= 필요한 논문의 갯수
            answer = citations.size() - i;
            break;
        }
    }
    return answer;
}
int main()
{
    vector<int> citations = { 1,6,6,6 };
    cout << solution(citations);
}