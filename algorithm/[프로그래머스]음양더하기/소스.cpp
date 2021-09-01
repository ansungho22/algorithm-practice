// 프로그래머스 음양더하기
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
	for (int i = 0; i < absolutes.size(); i++)
	{
		if (signs[i] == true)answer += absolutes[i];
		else
			answer -= absolutes[i];
	}
    return answer;
}