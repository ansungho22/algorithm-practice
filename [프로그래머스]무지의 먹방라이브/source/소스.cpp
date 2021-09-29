#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> foods; // first : 해당 음식 먹는데 필요한 시간, second : 번호 (정렬 전 원래 순서)
    int n = food_times.size();
    for (int i = 0; i < n; ++i)
        foods.push_back(make_pair(food_times[i], i + 1));
    sort(foods.begin(), foods.end()); // ⭐ "시간" 기준으로 오름차순 정렬
    int pretime = 0; // 이전에 다 먹을 수 있는 시간(음식)
    for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); ++it, --n) {  // 시간 순으로 정렬된 foods 순회 O(n)
        long long spend = (long long)(it->first - pretime) * n; // it 이 가리키는 음식을 다먹는데 걸리는 시간(이전 음식 이후)
        if (spend == 0) continue; // 이미 다 먹은 음식이므로 스킵 (이미 다 먹은 동일한 시간 음식)
        if (spend <= k) {  // k 에 아직 도달하지 못했다면 반복. 
            k -= spend; // k 는 방송 정지까지 남은 시간 
            pretime = it->first;
        }
        else { // spend > k
            k = k % n; // 이 과정 중요! 나머지로 하지 않고 그냥 k 만큼 전부 돌아버리면 시간 초과날 것이다. 내 첫 번쨰 풀이처럼
            // ⭐"번호(정렬 전 원래 순서)" 기준으로 오름차순 정렬.
            // it 반복자 원소부터!!! 정렬한다. 즉, [it ~ 마지막원소] 범위만 정렬한다.
            sort(it, foods.end(), comp);
            return (it + k)->second; // it 이 가리키는 음식부터 다 먹을 수 없는 것이기 때문에 it 이 가리키는 음식에서 원래 순서에서 k 칸을 더 가면 답!  
        }
    }
    return -1;
}