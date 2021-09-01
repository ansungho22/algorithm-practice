#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int measure_cnt(int measure) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(measure); i++) {
		if (measure % i == 0) {
			if (measure == i*i) {
				cnt++;
				continue;
			}
			cnt += 2;
		}
	}
	return cnt;
}

int solution(int left, int right) {
	int answer = 0;
	for (int i = left; i <= right; i++)
	{
		int a = measure_cnt(i);
		if (a % 2 == 0) {
			answer += i;
		}
		else {
			answer -= i;
		}
	}
	return answer;
}

int main() {
	cout << sqrt(16);
}