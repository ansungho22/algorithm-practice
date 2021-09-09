//น้มุ 1992น๘
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int arr[64][64];
void tree(int N, int x, int y) {

    int sum = 0;
    int size = N / 2;
    if (N == 1) {
        cout << arr[x][y];
        return;
    }
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (arr[i][j] == 1) {
                sum++;
            }
        }
    }
    if (sum == N * N) {
        cout << "1";
    }
    else if (sum == 0) {
        cout << "0";
    }
    else {
        cout << "(";
        tree(size, x, y);
        tree(size, x, y + size);
        tree(size, x + size, y);
        tree(size, x + size, y + size);
        cout << ")";
    }
}
int main() {
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            arr[i][j] = str[j] - '0';
        }
    }
    tree(N, 0, 0);
    return 0;
}