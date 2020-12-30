//프로그래머스 다리를 지나는 트럭
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int ans = 0;
	queue<int> q;
	int index = 0;
	int current_weight = 0;
	while (1) {
		if (index == truck_weights.size()) {
			ans += bridge_length;
			break;
		}
		ans++;

		if (q.size() == bridge_length) {
			current_weight -= q.front();
			q.pop();
		}
		if (current_weight + truck_weights[index] <= weight) {
			current_weight += truck_weights[index];
			q.push(truck_weights[index]);
			index++;
		}
		else {
			q.push(0);
		}
	}
	return ans;

}
