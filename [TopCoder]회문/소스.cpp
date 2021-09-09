#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

int find(string s) {
	int ans = s.length();
	int q = s.length()-1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == s[q]) {
			q -= 1;
		}
		else {
			ans += 1;
		}
	}

	return ans;
}

int main() {
	string s = "abdfhdyrbdbsdfghjkllkjhgfds";
	cout << find(s);
}