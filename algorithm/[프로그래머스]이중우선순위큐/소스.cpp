#include <string>
#include <vector>
#include <iostream>
#include<deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer = { 0, 0};
	deque<int> deq;
	for (auto s : operations) {
		int number = stoi(s.substr(2));
		if (s[0] == 'I') {
			deq.push_back(number);
			continue;
		}
		else if(s[0] == 'D'){
			if (!deq.empty()) {
				sort(deq.begin(), deq.end());
				if (number == 1) {
					deq.pop_back();
				}
				else {
					deq.pop_front();
				}
			}
		}
	}

	if (deq.empty())return answer;
	answer[0]=(deq.back());
	answer[1]=(deq.front());
	return answer;
}
int main() {
	vector<string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
	vector<int> ans = solution(operations);
	

}