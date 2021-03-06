//�Ա��ɻ�
#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
	long long sum = 0;
	int s = times.size();
	long long min = 1;
	long long max = (long long)times.back() * n;
	long long mid = (min + max) / 2;
	long long answer = max;
	while (min <= max) {
		sum = 0;
		mid = (min + max) / 2;
		for (int i = 0; i < s; i++)
			sum += mid / times[i];
		if (sum < n)
			min = mid + 1;
		else {
			if (mid <= answer)
				answer = mid;
			max = mid - 1;
		}
	}
	return answer;
}
int main() {
	int n = 6;
	vector<int> times = { 7,10 };
	cout << solution(n, times);
}