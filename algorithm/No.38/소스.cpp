#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}
int main() {
    vector<vector<int>> triangle = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };
    cout << solution(triangle);
}