//프로그래머스 프린터
#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max = priorities[0];
    queue<pair<int, int>> q;
    priority_queue <int> pque;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(priorities[i], i));
        pque.push(priorities[i]);
    }
    while (1) {
        int document = q.front().first;
        int index = q.front().second;
        q.pop();
        if (pque.top() == document) {
            pque.pop();
            answer++;
            if (index == location) {
                return answer;
            }
        }
        else {
            q.push(make_pair(document, index));
        }
    }
}