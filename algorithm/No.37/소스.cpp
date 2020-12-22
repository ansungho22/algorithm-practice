//น้มุ 10844น๘
#include <iostream>
#define MAX 1000000000
using namespace std;
int stairs[101][10] = { 0 };
int main(void) {
    int N;
    int ans = 0;
    cin >> N;

    for (int i = 1; i < 10; i++) {
        stairs[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        stairs[i][0] = stairs[i - 1][1];
        stairs[i][9] = stairs[i - 1][8];
        for (int j = 1; j < 9; j++) {
            stairs[i][j] = (stairs[i - 1][j - 1] + stairs[i - 1][j + 1]) % MAX;
        }
    }
    for (int i = 0; i <= 9; i++) {
        ans += stairs[N][i];
        ans %= MAX;
    }
    cout << ans;
}
