//น้มุ 2108น๘
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;

int main() {
	int N, temp, mode, max , min ;
	int Sum = 0, mx = -1;
	int arr[8001] = { 0, };
	cin >> N;
	vector<int> v, mode_v;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
		Sum += temp;
		temp = (temp <= 0) ? 4000 + temp : temp + 4000;
		arr[temp]++;
		if (arr[temp] > mx) {
			mx = arr[temp];
			mode = temp;
		}
	}
	sort(v.begin(), v.end());
	max = v.back()+4000;
	min = v.front()+4000;
	for (int i = min; i <= max; i++) {
		if (arr[i] == mx) {
			mode = i;
			mode = mode - 4000;
			mode_v.push_back(mode);
		}
	}
	mode = (mode_v.size() >= 2) ? mode_v[1] : mode_v[0];
	cout << round(float(Sum) / float(N)) << endl;
	cout << v[N / 2] << endl;
	cout << mode << endl;
	cout << v.back() - v.front() << endl;

}
