//프로그래머스 카펫
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	int all_grid = brown + yellow;
	int j;
	for (int i = 1; i <= all_grid/2; i++)
	{
		if ((all_grid % i) == 0) {
			j = all_grid / i;
			if ((i * 2 + (j - 2) * 2) == brown && all_grid - brown == yellow) {
				if (i < j) {
					answer.push_back(j);
					answer.push_back(i);
				}
				else {
					answer.push_back(i);
					answer.push_back(j);
				}
				break;
			}
		}
	}
    return answer;
}
int main() {
	int brown = 24;
	int yellow = 24;
	vector<int> v = solution(brown, yellow);
	for (auto i : v) {
		cout << i;
	}
}