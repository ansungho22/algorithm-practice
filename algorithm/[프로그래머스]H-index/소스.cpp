#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// ���α׷��ӽ� h-index
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        if (citations.size() - i <= citations[i]) { // ���� ���� �� <= �ʿ��� ���� ����
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