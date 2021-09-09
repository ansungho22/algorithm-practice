//¹éÁØ ±ÕÇüÀâÈù ¼¼»ó4949¹ø
#include<iostream>
#include<stack>
#include<vector>
#include <string>
using namespace std;
int main() {
	vector<string> v;
	string str;
	while (true) {
		getline(cin, str);
		if (str == ".")break;
		v.push_back(str);
	}
	for (int i = 0; i < v.size(); i++)
	{
		stack<char> s;
		for (int j = 0; j < v[i].size(); j++)
		{
			if ((v[i][j] == ']' || v[i][j] == ')')&& s.empty()) {
				v[i] = "no";
				break;
			}
			else if(v[i][j] == ']'){
				if (s.top()== '[')s.pop();
				else {
					v[i] = "no";
					break;
				}
			}
			else if (v[i][j] == ')') {
				if (s.top() == '(')s.pop();
				else {
					v[i] = "no";
					break;
				}
			}
			if (v[i][j] == '[' || v[i][j] == '(') {
				s.push(v[i][j]);
				continue;
			}
			if (j == v[i].size()-1 && s.empty())v[i] = "yes";
			else if(j == v[i].size() - 1 && !s.empty())v[i] = "no";
		}
	}
	for (auto i : v) {
		cout << i << endl;
	}
}