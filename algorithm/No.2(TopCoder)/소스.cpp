#include<iostream>
#include<stdlib.h>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	string frist[] = { "snakes","programming","cobra","monty" };
	string second[] = { "python","python","anaconda","python" };

	map<string, int> m;

	for (int i = 0; i < sizeof(frist)/sizeof(string); i++)
	{
		m[frist[i]] = 0;
		m[second[i]] = 0;
	}
	for (int i = 0; i < sizeof(frist) / sizeof(string); i++)
	{
		m[frist[i]]++;
		m[second[i]]++;
	}

	map<string, int>::iterator it;

	int ans = 0;

	for (it = m.begin(); it != m.end(); it++)
	{
		ans = max(ans, it->second);
	}

	cout << ans;
}