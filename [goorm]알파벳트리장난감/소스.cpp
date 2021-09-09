//구름 알파벳트리장남감 
#include<vector>
#include<algorithm>
#include<iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	string str;
	vector<int> v;
	int cnt = 0;
	cin >> N;
	int min_ans , max_ans;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			v.push_back(str[j] - '@');
		}
	}
	for (int i = 1; i < N-1; i++)
	{
		cnt += pow(2, i);
	}
	if (N == 2)cnt = 0;
	for (int i = 0; i <= cnt; i++)
	{
		v[i * 2 + 1] += v[i];
		v[i * 2 + 2] += v[i];
	}
	min_ans = v[cnt + 1];
	max_ans = v[cnt + 1];
	for (int i = cnt+1; i < v.size(); i++)
	{
		min_ans = min(min_ans, v[i]);
		max_ans = max(max_ans, v[i]);
	}
	cout << min_ans << endl;
	cout << max_ans << endl;
	return 0;
}