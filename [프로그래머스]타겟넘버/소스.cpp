//Å¸°Ù³Ñ¹ö
#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(int ans, vector<int> numbers, int target, int seq) {
    if (seq == numbers.size()) {
        if (ans == target)answer++;
        return;
    }
    dfs(ans + numbers[seq], numbers, target, seq + 1);
    dfs(ans - numbers[seq], numbers, target, seq + 1);
}
int solution(vector<int> numbers, int target) {
    dfs(0, numbers, target, 0);
    return answer;
}