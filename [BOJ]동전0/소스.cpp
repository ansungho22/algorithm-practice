// baekjon__11047
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main() {
	int N=0;
	int K=0;
	int temp=0;
	int count = 0; 
	vector<int> value;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		value.push_back(temp);
	}
	for (int i = N-1; i >= 0; i--) 
	{
		if (K == 0)break;
		if ((K / value[i]) > 0) { 
			temp = K / value[i] ; 
			K = K - (value[i] * temp); 
			count += temp; 
		}
	}
	cout << count;
}
