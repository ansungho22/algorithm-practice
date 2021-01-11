//Ã¼À°º¹
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student;
    for (int i = 0; i < n; i++)
    {
        student.push_back(1);
    }
    for (auto i : reserve) {
        student[i - 1]++;
    }
    for (auto i : lost) {
        student[i - 1]--;
    }
    for (auto i : lost) {
        if (student[i - 1] == 0) {
            if (student[i - 2] == 2) {
                student[i - 2]--;
                student[i - 1]++;
                continue;
            }
            else if (student[i] == 2) {
                student[i]--;
                student[i - 1]++;;
                continue;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (student[i] > 0)answer++;
    }
    

    return answer;
}
int main() {
    int n = 5;
    vector<int> lost = { 2,4 };
    vector<int> reserve = { 1,3,5 };
    cout << solution(n, lost, reserve);
}