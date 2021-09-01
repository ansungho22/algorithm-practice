#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
struct compare {
	bool operator()(pair<float, int>a, pair<float, int>b) {
		if (a.first == b.first) return a.second > b.second;
		else
			return a.first < b.first;
	}
};
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	priority_queue<pair<float, int>, vector<pair<float, int>>, compare> FailureRateStage;

	float UsersReachedStage[501] = { 0, };
	float UserChallengingStage[501] = { 0, };
	int Users = stages.size();

	sort(stages.begin(), stages.end());

	UserChallengingStage[1] = Users;

	for (int i : stages) {
		UsersReachedStage[i]++;
	}

	for (int i = 1; i < N + 1; i++) {
		UserChallengingStage[i + 1] = UserChallengingStage[i] - UsersReachedStage[i];
	}
	for (int i = 1; i < N + 1; i++) {
		if (UsersReachedStage[i] == 0 || UserChallengingStage[i] == 0) FailureRateStage.push(make_pair(0, i));
		else {
			FailureRateStage.push(make_pair((UsersReachedStage[i] / UserChallengingStage[i]), i));
		}
	}
	while (!FailureRateStage.empty()) {
		answer.push_back(FailureRateStage.top().second);
		FailureRateStage.pop();
	}
	for (auto i : answer) {
		cout << i << endl;
	}
	return answer;
}
int main() {
	vector<int> stages = { 4,4,4,4,4 };
	solution(5, stages);
}