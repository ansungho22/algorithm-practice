// baekjoon 6549 
#include<iostream>
#include<vector>
#include <algorithm>
#define FOR(i,N) for(int i =1;i<=N;i++)
typedef long long ll;
using namespace std;
vector<long long> list;
vector<long long> sort_list;

long long DP(int seq) {
	if (seq < 0)return 0;
	long long height = sort_list[seq];
	long long count = 0;
	long long area = 0;
	long long ans = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] >= height)
		{
			count++;
			if (count == list.size()) {
				area = height * count;
				ans = max(ans, area);
			}
		}
		else{
			area = height * count;
			ans = max(ans, area);
			count = 0;
		}
	}
	return max(ans,DP(seq-1));
}
int main() {
	long long ans = 0;
	long long size = 0;
	long long x;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		list.push_back(x);
	}
	sort_list = list;
	sort(sort_list.begin(), sort_list.end());
	ans = sort_list[size - 1] * 1;
	ans = max(ans,DP(size-1));
	cout << ans;
}