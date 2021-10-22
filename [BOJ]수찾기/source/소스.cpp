#include <iostream>
#include <vector>
#include<cstdio>
#include <algorithm>
using namespace std;


int BS(int key, vector<int> v) {
	int start = 0;
	int end = v.size() - 1;
	while (end>=start) {
		int mid = (start + end) / 2;
		if (v[mid] == key)
			return 1;
		else if (key > v[mid]) {
			start = mid+1;
		}
		else 
			end = mid-1;
		
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	int input;
	vector<int> A;
	vector<int> X;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		A.push_back(input);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		X.push_back(input);
	}

	sort(A.begin(), A.end());
	
	for (auto x : X)
		cout << BS(x, A)<<" ";

	return 0;
}