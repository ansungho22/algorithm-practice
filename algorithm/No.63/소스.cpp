//프로그래머스 구명보트
#include <string>
#include <vector>
#include <queue>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int limit_point = people.size()-1;
    deque<int> dq(people.begin(), people.end());
    sort(dq.begin(), dq.end());

    while (1) {
        if (dq.back() == limit) {
            answer++;
            dq.pop_back();
            if (dq.size() == 0)break;
        }
        int end_point = dq.size() - 1;
        if (dq.front() + dq.back() <= limit) {
            dq.back() += dq.front();
            dq.pop_front();
        }
        else if (dq.front() + dq.back() > limit) {
            while (dq.front() + dq[end_point] > limit) {
                end_point--;
                if (end_point == 0)break;
            }
            if (end_point == 0) break;
            dq[end_point] += dq.front();
            dq.pop_front();
            sort(dq.begin(), dq.end());

    
        }
    }
    return dq.size()+answer;
}
int main() {
    vector<int> people = { 160, 150, 140, 60, 50, 40 };
    int limit = 200;
    cout << solution(people,limit);
}
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<int> people, int limit) {
//    int answer = 0;
//    int head = 0, tail = people.size() - 1;
//    sort(people.begin(), people.end()); // 오름차순으로 정렬 
//
//    while (head <= tail) {
//        if (people[head] + people[tail] <= limit) {
//            head++;
//            tail--;
//        }
//        else { // 가장 작은 무게의 사람과 가장 많이 나가는 사람이 같이 못타는 경우에는 가장 많이 나가는 사람은 무조건 보트를 혼자 타야한다. 
//            tail--;
//        }
//        answer++;
//    }
//    return answer;
//}