//Â¡°Ë´Ù¸®
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {

    sort(rocks.begin(),rocks.end());
    long left = 1;
    long right = distance;
    long answer = 0;

    while (left <= right) {
        int removeRockCnt = 0;
        int prev = 0;
        long minDistance = (left + right) / 2;
        for (int rock : rocks) {
            if ((rock - prev) < minDistance) removeRockCnt++;
            else prev = rock;
        }
        if (distance - prev < minDistance) removeRockCnt++;
        if (removeRockCnt <= n) {
            answer = max(answer, minDistance);
            left = minDistance + 1;
        }
        else right = minDistance - 1;
    }
    return (int)answer;
}
int main() {
    int distance = 25;
    vector<int> rocks = { 2,14,11,21,17 };
    int n = 2;
    cout << solution(distance, rocks, n);
}