// 프로그래머스 내적
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int a_mul_b = a[i] * b[i];
		answer += a_mul_b;
	}
    return answer;
}