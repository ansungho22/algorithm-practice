#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> A;
	vector<int> B;
	int N = 0;
	int input = 0;
	int ans = 0;
	int mul = 0;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		A.push_back(input);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		B.push_back(input);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < N; i++)
	{
		mul = A[i] * B[N - 1 - i];
		ans += mul;
	}
	cout << ans;
}