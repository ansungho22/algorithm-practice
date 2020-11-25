//น้มุ 2108น๘
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;

int main() {
	int N,temp,Sum=0,mx=-1,mode;
	int arr[8001] = { 0, };
	cin >> N;
	vector<int> v,mode_v;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
		Sum += temp;
		temp = (temp <= 0) ? abs(temp) : temp + 4000;
		arr[temp]++;
		if (arr[temp] > mx) {
			mx = arr[temp];
			mode = temp;
		}
	}
	for (int i = 4001; i <= 8001; i++) {
		if (arr[i] == mx) {
			mode = i;
			mode = (mode <= 4000) ? -mode : mode - 4000;
			mode_v.push_back(mode);
		}
	}
	for (int i = 4000; i >=0; i--) {
		if (arr[i] == mx) {
			mode = i;
			mode = (mode <= 4000) ? -mode : mode - 4000;
			mode_v.push_back(mode);
		}
	}

	mode = (mode_v.size() >= 2) ? mode_v[1] : mode_v[0];
	sort(v.begin(),v.end());
	cout << (int)floor((Sum / N)+0.5) << endl;
	cout << v[N / 2] << endl;
	cout << mode << endl;
	cout << v.back() - v.front() << endl;

}
