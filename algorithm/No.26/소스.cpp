//구름 징검다리 건너기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N,inputINT;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{ 
		cin >> inputINT;
		v.push_back(inputINT);
	}
	for (int i = 3; i < N; i++)
	{
		v[i] += min(min(v[i - 1], v[i - 2]),min(v[i-2], v[i - 3]));
	}
	cout << min(min(v[N - 1], v[N - 2]), min(v[N - 2], v[N - 3]));
	return 0;
}