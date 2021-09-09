#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include<iostream>
using namespace std;
struct compare {
    bool operator()(vector<int>a,vector<int>b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int ans = 0 , time = 0, seq = 0;
    priority_queue < vector<int>, vector<vector<int>>, compare> pq;
    while (!pq.empty() || seq < jobs.size()) {
        if (seq < jobs.size() && time >= jobs[seq][0]) {
            pq.push(jobs[seq]);
            seq++;
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            ans += time - pq.top()[0];
            pq.pop();
        }
        else {
            time = jobs[seq][0];
        }
    }

    return ans/jobs.size();
}
int main(){
    vector<vector<int>> v = { {2,6} ,{0,3},{1,9} };
    cout << solution(v);
}