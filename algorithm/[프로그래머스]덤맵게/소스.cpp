// 프로그래머스 더 맵게
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int lowlow_scoville;
	int low_scoville;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
	while (pq.top() < K) {
		if (pq.size() == 1) return answer = -1;
		
		lowlow_scoville = pq.top();
		pq.pop();
		
		low_scoville = pq.top();
		pq.pop();
		
		pq.push(lowlow_scoville + (low_scoville * 2));
		answer++;
	}
	return answer;
}

