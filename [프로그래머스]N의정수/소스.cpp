// 프로그래머스 N의 정수

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
int x[8] = { 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111 };
using namespace std;

int solution(int N, int number) {
	int answer = 0;
	vector<set<int>> arr(8);
	for (int i = 0; i < 8; i++) {
		int n = 0;
		n = x[i] * N;
		arr[i].insert(n);
		if (arr[i].find(number) != arr[i].end()) {
			return i + 1;
		}
	}
	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			for (auto& x : arr[j]) {
				for (auto& y : arr[i - j - 1]) {
					arr[i].insert(x + y);
					arr[i].insert(x * y);
					arr[i].insert(x - y);
					if (y != 0) arr[i].insert(x / y);
				}
			}
		}
		if (arr[i].find(number) != arr[i].end()) {
			return i + 1;
		}
	}
	return -1;
}
