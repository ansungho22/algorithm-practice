//프로그래머스 깊이/너비 우선 타켓넘버
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int numSize;
int answer = 0;
void dfs(int idx, int sum, int target, vector<int>& numbers) {
    if (idx == numSize) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    dfs(idx + 1, sum + numbers[idx], target, numbers);
    dfs(idx + 1, sum - numbers[idx], target, numbers);
}
int solution(vector<int> numbers, int target) {
    numSize = numbers.size();
    dfs(0, 0, target, numbers);
    return answer;
}