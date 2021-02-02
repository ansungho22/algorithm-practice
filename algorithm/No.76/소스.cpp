//Â¡°Ë´Ù¸®
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int l = 0;
    int r = distance;
    while (l <= r) {
        int mid = (l + r) / 2;
        int removeIdx = -1;
        int removeCount = 0;
        for (int i = 0; i <= rocks.size(); i++) {
            int d;
            if (i == 0) {
                d = rocks[i];
            }
            else {
                if (i == rocks.size()) d = distance - rocks[rocks.size() - 1];
                else d = rocks[i] - rocks[removeIdx];
            }
            if (d < mid) removeCount++;
            else removeIdx = i;
        }
        if (removeCount > n) {
            r = mid - 1;
        }
        else if (removeCount <= n) {
            l = mid + 1;
            answer = max(answer, mid);
        }
    }

    return answer;
}