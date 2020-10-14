//baekjoon_1541
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	vector<int> a;
	int n = 0;
	cin >> s;
	a.push_back(stoi(s));
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+')
			a.back() += stoi(s.substr(i + 1, 6));
		else if (s[i] == '-') {
			a.push_back(stoi(s.substr(i + 1, 6)));
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		n -= a[i];
	}

	cout << n + (a[0] * 2)  << endl;
	return 0;
}