#include <iostream>
#include<string>
#include<vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
	vector<char> v;
	for (auto c : s) {
		if (v.empty())v.push_back(c);
		else {
			if (c == v.back()) v.pop_back();
			else {
				v.push_back(c);
			}
		}
	}
	if (v.empty())return 1;
	return 0;
}
