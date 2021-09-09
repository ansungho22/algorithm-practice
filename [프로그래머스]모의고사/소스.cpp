//프로그래머스 모의고사 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v1 = { 1,2,3,4,5 };
vector<int> v2 = { 2,1,2,3,2,4,2,5 };
vector<int> v3 = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> score = { 0,0,0 };
	vector<int> ans;
	int big = 0;
	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == v1[i % 5])score[0]++;
		if (answers[i] == v2[i % 8])score[1]++;
		if (answers[i] == v3[i % 10])score[2]++;
	}
	big = max(max(score[0], score[1]), score[2]);
	for (int i = 0; i < 3; i++) {
		if (big == score[i])ans.push_back(i + 1);
	}
	return ans;
}