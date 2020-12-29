//프로그래머스 기능개발
#include <string>
#include <vector>
#include <iostream>
#include<stack>
#include<math.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	for (int i = 0; i < progresses.size(); i++)
	{
		progresses[i] = (int)ceil((double)(100 - progresses[i])/(double)speeds[i]);
	}
	int max=progresses.front();
	int cnt = 0;
	for (int i = 0; i < progresses.size(); i++)
	{
		if (progresses[i] > max) {
			answer.push_back(cnt);
			cnt = 1;
			max = progresses[i];
			continue;
		}
		cnt++;
	}
	answer.push_back(cnt);
	
    return answer;
}
