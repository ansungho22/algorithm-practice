#include <vector>
#include <algorithm>
//공부해보기 ...발전하자
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int temp = routes[0][1];
    for (auto a : routes) {
        if (temp < a[0]) {
            answer++;
            temp = a[1];
        }
        if (temp >= a[1])    temp = a[1];
    }
    return answer;
}