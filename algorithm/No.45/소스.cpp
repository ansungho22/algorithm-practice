//프로그래머스 다리를 지나는 트럭
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int ans = 0;
	int current_weight = 0;
	int current_move_truck = 0;
	for (int i = 0; i < truck_weights.size(); i++) {
		current_weight += truck_weights[i];
		if (current_weight > weight ) {
			ans += (current_move_truck - 1) * 1 + bridge_length;
			current_move_truck = 0;
			current_move_truck++;
			current_weight = truck_weights[i];
		}
		else {
			current_move_truck++;
		}
	}
	if (current_move_truck != 0) {
		ans += (current_move_truck - 1) * 1 + bridge_length;
	}
	ans++;

	return ans;
}
int main() {
	int bridge_length = 5;
	int weight = 5;
	vector<int> truck_weights = { 2, 2, 2, 2, 1, 1, 1, 1, 1 };
	solution(bridge_length, weight, truck_weights);
}